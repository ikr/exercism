#include "word_count.h"
#include <algorithm>
#include <locale>
#include <regex>

namespace {
std::string to_lower(std::string s) {
    static const std::locale loc{};
    std::transform(s.cbegin(), s.cend(), s.begin(),
                   [](const char c) { return std::tolower(c, loc); });
    return s;
}
} // namespace

namespace word_count {
std::map<std::string, int> words(const std::string &phrase) {
    std::regex word_regex{"(o')?[a-zA-Z0-9]+('t|'s)?"};

    auto words_begin =
        std::sregex_iterator(phrase.cbegin(), phrase.cend(), word_regex);

    auto words_end = std::sregex_iterator();
    std::map<std::string, int> ans;

    for (auto it = words_begin; it != words_end; ++it) {
        ++ans[to_lower(it->str())];
    }

    return ans;
}
} // namespace word_count
