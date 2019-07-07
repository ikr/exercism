#include "sum_of_multiples.h"
#include <algorithm>

namespace {
void remove_multiples_of_others(std::vector<int> &xs) {
    xs.erase(std::remove_if(xs.begin(), xs.end(),
                            [ys = xs](const int x) {
                                return std::any_of(
                                    ys.cbegin(), ys.cend(), [x](const int y) {
                                        return x % y == 0 && x / y > 1;
                                    });
                            }),
             xs.end());
}

void dedupe(std::vector<int> &xs) {
    std::sort(xs.begin(), xs.end());
    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
}
} // namespace

namespace sum_of_multiples {
int to(std::vector<int> xs, const int upper_bound) {
    dedupe(xs);
    remove_multiples_of_others(xs);

    int ans = 0;

    for (int i = 1; i < upper_bound; ++i)
        if (any_of(xs.cbegin(), xs.cend(),
                   [i](const int x) { return i % x == 0; }))
            ans += i;

    return ans;
}
} // namespace sum_of_multiples
