#include "all_your_base.h"

namespace {

unsigned int total_value(unsigned int in_base,
                         const all_your_base::digits &in_digits) {
    if (in_digits.size() && !in_digits[0])
        return 0;

    unsigned int result = 0;
    for (auto i = in_digits.begin(); i != in_digits.end(); ++i) {
        if (*i >= in_base)
            return 0;

        result = in_base * result + *i;
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
        result.insert(result.begin(), remainder % out_base);
        remainder /= out_base;
    }

    return result;
}

} // namespace all_your_base
