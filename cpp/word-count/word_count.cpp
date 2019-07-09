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
    std::map<std::string, int> ans;
    std::regex word_regex{"(o')?[\\w]+('t|'s)?"};

    for (auto it =
             std::sregex_iterator(phrase.cbegin(), phrase.cend(), word_regex);
         it != std::sregex_iterator(); ++it) {
        ++ans[to_lower(it->str())];
    }

    return ans;
}
} // namespace word_count
