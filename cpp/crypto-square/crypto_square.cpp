#include "crypto_square.h"
#include <algorithm>
#include <locale>

namespace {
std::string lowercase(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](char c) { return std::tolower(c, std::locale()); });
    return s;
}
} // namespace

namespace crypto_square {
cipher::cipher(const std::string &clear_text) : m_clear_text(clear_text) {}

std::string cipher::normalize_plain_text() const {
    return lowercase(m_clear_text);
}
} // namespace crypto_square
