#include "prime_factors.h"

namespace prime_factors {
std::vector<int> of(int x) {
    std::vector<int> answer;

    for (int divider = 2; divider * divider <= x; ++divider) {
        while (x % divider == 0) {
            answer.push_back(divider);
            x /= divider;
        }
    }

    if (x > 1) answer.push_back(x);
    return answer;
}
} // namespace prime_factors
