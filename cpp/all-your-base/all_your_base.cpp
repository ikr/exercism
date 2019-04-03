#include "all_your_base.h"
#include <algorithm>

namespace {

unsigned int total_value(const unsigned int base,
                         const all_your_base::digits &xs) {
    if (xs.size() && !xs[0])
        return 0;

    unsigned int result = 0;

    for (auto x : xs) {
        if (x >= base)
            return 0;

        result = base * result + x;
    }

    return result;
}

all_your_base::digits represent(const unsigned int value,
                                const unsigned int base) {
    if (base < 2)
        return all_your_base::digits{};

    unsigned int remainder = value;
    all_your_base::digits result;

    while (remainder > 0) {
        result.push_back(remainder % base);
        remainder /= base;
    }

    std::reverse(result.begin(), result.end());
    return result;
}

} // namespace

namespace all_your_base {

digits convert(const unsigned int in_base, const digits &in_digits,
               const unsigned int out_base) {
    return represent(total_value(in_base, in_digits), out_base);
}

} // namespace all_your_base
