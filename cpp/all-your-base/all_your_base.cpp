#include "all_your_base.h"

namespace all_your_base {

digits convert(unsigned int in_base, const digits &in_digits, unsigned int out_base) {
    digits result(in_digits);
    result.push_back(in_base);
    result.push_back(out_base);
    return result;
}

} // namespace all_your_base
