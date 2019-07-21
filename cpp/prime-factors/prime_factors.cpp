#include "prime_factors.h"
#include <algorithm>

namespace {
int first_prime_larger_than(const int x) {
    static std::vector<int> primes{2,  3,  5,  7,  11, 13, 17,
                                   19, 23, 29, 31, 37, 41};
    const auto it = std::upper_bound(primes.cbegin(), primes.cend(), x);
    if (it != primes.cend()) return *it;

    while (primes.back() <= x) {
        int i = primes.back() + 1;
        while (std::any_of(primes.cbegin(), primes.cend(),
                           [i](const int p) { return i % p == 0; })) {
            ++i;
        }
        primes.push_back(i);
    }

    return primes.back();
}
} // namespace

namespace prime_factors {
std::vector<int> of(const int x) {
    if (x < 2) return {};

    std::vector<int> answer;

    int remainder = x;
    int divider = 2;
    while (remainder != 1) {
        while (remainder % divider == 0) {
            answer.push_back(divider);
            remainder /= divider;
        }

        divider = first_prime_larger_than(divider);
    }

    return answer;
}
} // namespace prime_factors
