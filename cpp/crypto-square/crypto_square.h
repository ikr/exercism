#ifndef CRYPTO_SQUARE_H
#define CRYPTO_SQUARE_H
#include <string>

namespace crypto_square {
struct cipher final {
    cipher(const std::string &clear_text);
    std::string normalize_plain_text() const;

private:
    std::string m_clear_text;
};
} // namespace crypto_square

#endif //CRYPTO_SQUARE_H
