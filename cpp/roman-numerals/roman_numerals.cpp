#include "roman_numerals.h"
#include <cassert>

namespace roman_numerals {
std::string convert(const int n) {
    assert(n > 0);
    return std::string(n, 'I');
}
} // namespace roman_numerals
