#include "crypto_square.h"
#include <algorithm>
#include <locale>
#include <utility>

namespace {
using WidthHeight = std::pair<size_t, size_t>;

WidthHeight text_rect_dimensions(const size_t source_text_length) {
    size_t w = 0;
    while (w * w < source_text_length) ++w;

    const size_t h = w * w == source_text_length ? w : w - 1;
    return std::make_pair(w, h);
}
} // namespace

namespace crypto_square {
cipher::cipher(const std::string &clear_text) : m_clear_text(clear_text) {}

std::string cipher::normalize_plain_text() const {
    static std::locale lc;

    std::string result;
    std::copy_if(m_clear_text.begin(), m_clear_text.end(),
                 std::back_inserter(result), [](const char c) {
                     return std::isalpha(c, lc) || std::isdigit(c, lc);
                 });

    std::transform(result.begin(), result.end(), result.begin(),
                   [](char c) { return std::tolower(c, lc); });

    return result;
}

std::vector<std::string> cipher::plain_text_segments() const {
    std::vector<std::string> result;

    const auto normalized = normalize_plain_text();
    const WidthHeight dim = text_rect_dimensions(normalized.size());

    for (size_t i = 0; i < normalized.size(); i += dim.first) {
        result.push_back(normalized.substr(i, dim.first));
    }
    return result;
}

std::string cipher::cipher_text() const {
    std::string result;
    const WidthHeight dim = text_rect_dimensions(normalize_plain_text().size());
    const auto rows = plain_text_segments();

    for (size_t j = 0; j != dim.first; ++j) {
        for (size_t i = 0; i != dim.second; ++i) {
            const auto row = rows[i];
            if (j < row.size()) result += row[j];
        }
    }

    return result;
}

} // namespace crypto_square
