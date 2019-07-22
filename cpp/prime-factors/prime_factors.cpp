#include "prime_factors.h"

namespace prime_factors {
std::vector<int> of(const int x) {
    if (x < 2) return {};

    std::vector<int> answer;
    int remainder = x;

    for (int divider = 2; divider * divider <= remainder; ++divider) {
        while (remainder % divider == 0) {
            answer.push_back(divider);
            remainder /= divider;
        }
    }

    if (remainder != 1) answer.push_back(remainder);

    return answer;
}
} // namespace prime_factors
