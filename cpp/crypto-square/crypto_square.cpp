#include "crypto_square.h"
#include <algorithm>
#include <locale>

namespace crypto_square {
cipher::cipher(const std::string &clear_text) : m_clear_text(clear_text) {}

std::string cipher::normalize_plain_text() const {
    static std::locale lc;

    std::string result;
    std::copy_if(
        m_clear_text.begin(), m_clear_text.end(), std::back_inserter(result),
        [](const char c) { return std::isalpha(c, lc) || std::isdigit(c, lc); });

    std::transform(result.begin(), result.end(), result.begin(),
                   [](char c) { return std::tolower(c, lc); });

    return result;
}
} // namespace crypto_square
