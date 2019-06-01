#ifndef ANAGRAM_H
#define ANAGRAM_H
#include <string>
#include <vector>

namespace anagram {
struct anagram {
    anagram(const std::string &src);

    std::vector<std::string>
    matches(const std::vector<std::string> &candidates) const;

private:
  std::string m_sorted_letters;
  std::string m_original;
};
} // namespace anagram

#endif // ANAGRAM_H
