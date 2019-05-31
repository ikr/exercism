#ifndef ANAGRAM_H
#define ANAGRAM_H
#include <string>
#include <vector>

namespace anagram {
struct anagram {
    anagram(const std::string &src);

    std::vector<std::string>
    matches(const std::vector<std::string> &candidates) const;
};
} // namespace anagram

#endif // ANAGRAM_H
