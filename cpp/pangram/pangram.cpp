#include "pangram.h"
#include <bitset>
#include <locale>

namespace pangram {

constexpr auto letters_count = 'z' - 'a' + 1;

char normalize(const char x) { return std::tolower(x, std::locale::classic()); }

bool is_letter(const char x) {
    const char nx = normalize(x);
    return nx >= 'a' && nx <= 'z';
}

bool is_pangram(const std::string &xs) {
    std::bitset<letters_count> seen;

    for (const auto x : xs) {
        if (is_letter(x)) {
            seen[normalize(x)] = true;

            if (seen.count() == letters_count)
                return true;
        }
    }

    return false;
}

} // namespace pangram
