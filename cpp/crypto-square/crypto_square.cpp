#include "crypto_square.h"
#include <algorithm>
#include <locale>

namespace {
struct Dimensions final {
    size_t width;
    size_t height;
};

Dimensions text_rect_dimensions(const size_t source_text_length) {
    size_t w = 0;
    while (w * w < source_text_length) ++w;

    const size_t h = (w * w == source_text_length ? w : w - 1);
    return Dimensions{w, h};
}

std::string
build_cipher_text(const std::string &normalized_plain_text,
                  const std::vector<std::string> &plain_text_segments,
                  const std::string &spacer) {
    std::string result;
    const Dimensions dim = text_rect_dimensions(normalized_plain_text.size());

    for (size_t j = 0; j != dim.width; ++j) {
        if (result.size()) result += spacer;

        for (size_t i = 0; i != dim.height; ++i) {
            const auto row = plain_text_segments[i];

            if (j < row.size())
                result += row[j];
            else
                result += spacer;
        }
    }

    return result;
}
} // namespace

namespace crypto_square {
cipher::cipher(const std::string &plain_text) : m_plain_text(plain_text) {}

std::string cipher::normalize_plain_text() const {
    static std::locale lc;

    std::string result;
    std::copy_if(m_plain_text.begin(), m_plain_text.end(),
                 std::back_inserter(result),
                 [](const char c) { return std::isalnum(c, lc); });

    std::transform(result.begin(), result.end(), result.begin(),
                   [](char c) { return std::tolower(c, lc); });

    return result;
}

std::vector<std::string> cipher::plain_text_segments() const {
    std::vector<std::string> result;

    const auto normalized = normalize_plain_text();
    const Dimensions dim = text_rect_dimensions(normalized.size());

    for (size_t i = 0; i < normalized.size(); i += dim.width) {
        result.push_back(normalized.substr(i, dim.width));
    }
    return result;
}

std::string cipher::cipher_text() const {
    return build_cipher_text(normalize_plain_text(), plain_text_segments(), "");
}

std::string cipher::normalized_cipher_text() const {
    return build_cipher_text(normalize_plain_text(), plain_text_segments(),
                             " ");
}
} // namespace crypto_square
