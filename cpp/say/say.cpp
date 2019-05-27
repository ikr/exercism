#include "say.h"
#include <cassert>
#include <stdexcept>
#include <vector>

namespace {
using ull_t = unsigned long long;
constexpr ull_t max_spoken = 999999999999;

std::string say_0_to_19(const ull_t x) {
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
        "",      "",      "twenty",  "thirty", "forty",
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
        result += say_0_to_19(units);
    }

    return result;
}

std::string say_0_to_99(const ull_t x) {
    assert(x >= 0);
    assert(x < 100);

    return x < 20 ? say_0_to_19(x) : say_20_to_99(x);
}

std::string say_100_to_999(const ull_t x) {
    assert(x >= 100);
    assert(x < 1000);

    const ull_t hundreds = x / 100;
    std::string result = say_0_to_19(hundreds);
    result += " hundred";

    const ull_t remainder = x % 100;

    if (remainder) {
        result += ' ';
        result += say_0_to_99(remainder);
    }

    return result;
}

std::string say_0_to_999(const ull_t x) {
    assert(x >= 0);
    assert(x < 1000);

    if (x < 100) return say_0_to_99(x);
    return say_100_to_999(x);
}

ull_t pow(const ull_t base, const ull_t exponent) {
    ull_t result = 1;

    for (ull_t i = 0; i < exponent; ++i) {
        result *= base;
    }

    return result;
}
} // namespace

namespace say {
std::string in_english(const ull_t x) {
    if (x < 0 || x > max_spoken)
        throw std::domain_error("Expecting 0 ≤ x ≤ " +
                                std::to_string(max_spoken));

    static const std::vector<std::string> group_suffix = {
        "", " thousand", " million", " billion"};

    assert(pow(1000, group_suffix.size()) - 1 == max_spoken);

    std::string result = "";
    ull_t remainder = x;
    ull_t power_of_1000 = 3;

    for (;;) {
        const ull_t divider = pow(1000, power_of_1000);
        const ull_t group_value = remainder / divider;

        if (group_value) {
            if (result.size()) result += " ";
            result += say_0_to_999(group_value) + group_suffix[power_of_1000];
        }

        remainder = remainder % divider;
        if (power_of_1000 == 0) break;
        --power_of_1000;
    }

    return result.size() ? result : "zero";
}
} // namespace say
