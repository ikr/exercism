#include "all_your_base.h"
#include <algorithm>

namespace {

unsigned int total_value(unsigned int in_base,
                         const all_your_base::digits &in_digits) {
    if (in_digits.size() && !in_digits[0])
        return 0;

    unsigned int result = 0;
    for (auto d : in_digits) {
        if (d >= in_base)
            return 0;

        result = in_base * result + d;
    }

    return result;
}

} // namespace

namespace all_your_base {

digits convert(unsigned int in_base, const digits &in_digits,
               unsigned int out_base) {
    if (out_base < 2)
        return digits{};

    unsigned int remainder = total_value(in_base, in_digits);
    digits result;

    while (remainder > 0) {
        result.push_back(remainder % out_base);
        remainder /= out_base;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

} // namespace all_your_base
