#ifndef ALL_YOUR_BASE_H
#define ALL_YOUR_BASE_H

#include <vector>

namespace all_your_base {

using digits = std::vector<unsigned int>;

digits convert(const unsigned int in_base, const digits &in_digits,
               const unsigned int out_base);

} // namespace all_your_base

#endif // ALL_YOUR_BASE_H
