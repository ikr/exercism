#include "armstrong_numbers.h"
#include <algorithm>
#include <cassert>
#include <numeric>
#include <vector>

namespace {
int iexp(const int base, const size_t power) {
    if (!power) return 1;
    if (power % 2) return base * iexp(base, power - 1);
    const int sqr = iexp(base, power / 2);
    return sqr * sqr;
}

std::vector<int> digits(const int x) {
    std::vector<int> result;
    int remainder = x;

    while (remainder) {
        result.push_back(remainder % 10);
        remainder /= 10;
    }

    reverse(result.begin(), result.end());
    return result;
}
} // namespace

namespace armstrong_numbers {
bool is_armstrong_number(const int x) {
    auto xs = digits(x);
    const size_t power = xs.size();

    std::transform(xs.begin(), xs.end(), xs.begin(),
                   [power](int x) { return iexp(x, power); });

    return std::accumulate(xs.begin(), xs.end(), 0) == x;
}
} // namespace armstrong_numbers
