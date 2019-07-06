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
    return n < 6 ? 9
                 : static_cast<int>(n * (std::log(n) + std::log(std::log(n))));
}

/**
 * See https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
 */
int sieve_primes_return_nth(const int value_limit, const int n) {
    std::vector<bool> scratchpad(value_limit + 1, true);
    std::fill_n(scratchpad.begin(), 2, false);

    int count = 1;
    for (auto i = scratchpad.begin() + 2; i != scratchpad.end();
         i = std::find(i + 1, scratchpad.end(), true), ++count) {
        const int current_divider = std::distance(scratchpad.begin(), i);
        if (count == n) return current_divider;

        for (auto idx = 2 * current_divider; idx <= value_limit;
             idx += current_divider) {
            scratchpad[idx] = false;
        }
    }

    throw std::logic_error("Couldn't reach the nth prime in the sieve");
}
} // namespace

namespace prime {
int nth(const int n) {
    if (n < 1) throw std::domain_error("Primes are counted from 1");
    return sieve_primes_return_nth(nth_prime_upper_bound(n), n);
}
} // namespace prime
