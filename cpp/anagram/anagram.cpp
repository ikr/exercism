#include "anagram.h"
#include <algorithm>
#include <locale>

namespace {
std::string lowercase(std::string s) {
    std::transform(s.begin(), s.end(), s.begin(),
                   [](char c) { return std::tolower(c, std::locale()); });
    return s;
}

std::string sort_lowercased(std::string s) {
    s = lowercase(s);
    std::sort(s.begin(), s.end());
    return s;
}
} // namespace

namespace anagram {
anagram::anagram(const std::string &word)
    : m_sorted_letters{sort_lowercased(word)}, m_original_lowercased{
                                                   lowercase(word)} {}

std::vector<std::string>
anagram::matches(const std::vector<std::string> &candidates) const {
    std::vector<std::string> result;

    std::copy_if(candidates.begin(), candidates.end(),
                 std::back_inserter(result), [this](std::string word) {
                     return sort_lowercased(word) == m_sorted_letters &&
                            lowercase(word) != m_original_lowercased;
                 });

    return result;
}
} // namespace anagram
