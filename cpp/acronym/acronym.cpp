#include "acronym.h"
#include <algorithm>
#include <locale>
#include <regex>

namespace acronym {
std::string acronym(const std::string &text) {
    std::string result;
    std::regex word_pattern{"[[:alpha:]]+"};

    std::transform(
        std::sregex_token_iterator(text.cbegin(), text.cend(), word_pattern),
        std::sregex_token_iterator(), std::back_inserter(result),
        [](const std::string &word) {
            return std::toupper(word[0], std::locale::classic());
        });

    return result;
}
} // namespace acronym
