#ifndef ATBASH_CIPHER_H
#define ATBASH_CIPHER_H

#include <string>

namespace atbash {
std::string encode(const std::string &text);
std::string decode(const std::string &text);
} // namespace atbash

#endif // ATBASH_CIPHER_H
