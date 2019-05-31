#include "anagram.h"
#include <cassert>

namespace anagram {
anagram::anagram(const std::string &src) { assert(src.size()); }

std::vector<std::string>
anagram::matches(const std::vector<std::string> &candidates) const {
    return candidates;
}
} // namespace anagram
