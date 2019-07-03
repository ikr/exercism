#include "sieve.h"
#include <algorithm>

namespace sieve {
std::vector<int> primes(const int limit) {
    std::vector<bool> scratchboard(limit + 1, true);
    std::fill_n(scratchboard.begin(), 2, false);

    for (auto i = scratchboard.begin() + 2; i != scratchboard.end();
         i = find(i + 1, scratchboard.end(), true)) {
        const int current_divider = std::distance(scratchboard.begin(), i);

        for (auto idx = 2 * current_divider; idx <= limit;
             idx += current_divider) {
            scratchboard[idx] = false;
        }
    }

    std::vector<int> ans;
    for (auto idx = 2; idx <= limit; ++idx) {
        if (scratchboard[idx]) ans.push_back(idx);
    }
    return ans;
}
} // namespace sieve
