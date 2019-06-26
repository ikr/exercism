#include "isogram.h"
#include <algorithm>
#include <locale>
#include <unordered_set>

namespace isogram {
bool is_isogram(std::string s) {
    s.erase(std::remove_if(s.begin(), s.end(),
                           [](const char c) { return c == ' ' || c == '-'; }),
            s.cend());

    std::transform(s.cbegin(), s.cend(), s.begin(),
                   [](const char c) { return std::tolower(c, std::locale()); });

    std::unordered_set<char> letters(s.cbegin(), s.cend());
    return letters.size() == s.size();
}
} // namespace isogram
