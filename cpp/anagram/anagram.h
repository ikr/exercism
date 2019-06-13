#ifndef ANAGRAM_H
#define ANAGRAM_H
#include <string>
#include <vector>

namespace anagram {
struct anagram final {
    anagram(const std::string &src);

    std::vector<std::string>
    matches(const std::vector<std::string> &candidates) const;

  private:
    const std::string m_sorted_letters;
    const std::string m_original_lowercased;
};
} // namespace anagram

#endif // ANAGRAM_H
