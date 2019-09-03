#include "atbash_cipher.h"
#include <algorithm>
#include <cassert>
#include <locale>

namespace {
char encode_lowercase_symbol(const char symbol) {
    assert('a' <= symbol && symbol <= 'z');
    const unsigned int distance_to_z = 'z' - symbol;
    return 'a' + distance_to_z;
}
} // namespace

namespace atbash {
std::string encode(const std::string &text) {
    std::string result{text};
    result.erase(std::remove_if(result.begin(), result.end(),
                                [](const char symbol) {
                                    return !std::isalnum(
                                        symbol, std::locale::classic());
                                }),
                 result.end());

    std::transform(result.cbegin(), result.cend(), result.begin(),
                   [](const char symbol) {
                       return encode_lowercase_symbol(
                           std::tolower(symbol, std::locale::classic()));
                   });
    return result;
}
} // namespace atbash
