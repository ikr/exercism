#include "sieve.h"
#include <algorithm>
#include <iterator>

namespace sieve {
std::vector<int> primes(const int limit) {
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
} // namespace sieve
