#include "atbash_cipher.h"
#include <algorithm>
#include <cassert>
#include <locale>

namespace {
constexpr char encode_lowercase_symbol(const char symbol) {
    assert('a' <= symbol && symbol <= 'z');
    const unsigned int distance_to_z = 'z' - symbol;
    return 'a' + distance_to_z;
}

constexpr unsigned int cipher_block_size = 5U;
const auto loc = std::locale::classic();
} // namespace

namespace atbash {
std::string decode(const std::string &text) {
    std::string result{text};

    result.erase(std::remove_if(result.begin(), result.end(),
                                [](const char symbol) {
                                    return !std::isalnum(symbol, loc);
                                }),
                 result.end());

    std::transform(
        result.cbegin(), result.cend(), result.begin(), [](const char symbol) {
            return std::isalpha(symbol, loc)
                       ? encode_lowercase_symbol(std::tolower(symbol, loc))
                       : symbol;
        });

    return result;
}

std::string encode(const std::string &text) {
    std::string result{decode(text)};

    for (unsigned int i = cipher_block_size; i < result.size();
         i += cipher_block_size + 1) {
        result.insert(i, 1, ' ');
    }

    return result;
}
} // namespace atbash
