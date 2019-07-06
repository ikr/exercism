#include "nth_prime.h"
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <vector>

namespace {
/**
 * See
 * https://en.wikipedia.org/wiki/Prime_number_theorem#Approximations_for_the_nth_prime_number
 */
constexpr int nth_prime_upper_bound(const int n) {
    return n < 6
               ? 9
               : static_cast<int>(n * std::log(n) + n * std::log(std::log(n)));
}

/**
 * See https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 */
std::vector<int> sieve_primes(const int limit) {
    std::vector<int> ans;
    std::vector<bool> scratchpad(limit + 1, true);
    std::fill_n(scratchpad.begin(), 2, false);

    for (auto i = scratchpad.begin() + 2; i != scratchpad.end();
         i = std::find(i + 1, scratchpad.end(), true)) {
        const int current_divider = std::distance(scratchpad.begin(), i);
        ans.push_back(current_divider);

        for (auto idx = 2 * current_divider; idx <= limit;
             idx += current_divider) {
            scratchpad[idx] = false;
        }
    }

    return ans;
}
} // namespace

namespace prime {
int nth(const int n) {
    if (n < 1) throw std::domain_error("Primes are counted from 1");
    const auto primes = sieve_primes(nth_prime_upper_bound(n));
    return primes[n - 1];
}
} // namespace prime
