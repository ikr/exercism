#include "say.h"
#include <cassert>
#include <stdexcept>
#include <vector>

namespace {
using ull_t = unsigned long long;

std::string say_0_to_20(const ull_t x) {
    assert(x >= 0);
    assert(x < 20);

    static const std::vector<std::string> names{
        "zero",    "one",     "two",       "three",    "four",
        "five",    "six",     "seven",     "eight",    "nine",
        "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
        "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

    return names[x];
}

std::string say_dozens(const ull_t x) {
    assert(x > 1);
    assert(x < 10);

    static const std::vector<std::string> names{
        "",      "",      "twenty",  "thirty", "fourty",
        "fifty", "sixty", "seventy", "eighty", "ninety"};

    return names[x];
}

std::string say_20_to_99(const ull_t x) {
    assert(x >= 20);
    assert(x < 100);

    const ull_t dozens = x / 10;
    const ull_t units = x % 10;

    std::string result = say_dozens(dozens);

    if (units) {
        result += '-';
        result += say_0_to_20(units);
    }

    return result;
}
} // namespace

namespace say {
std::string in_english(const ull_t x) {
    if (x < 20) return say_0_to_20(x);
    if (x < 100) return say_20_to_99(x);
    throw std::domain_error("Expecting 0 ≤ x ≤ 999'999'999'999");
}
} // namespace say
