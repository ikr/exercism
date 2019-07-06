#include "sum_of_multiples.h"
#include <algorithm>
#include <functional>
#include <numeric>
#include <unordered_set>

namespace {
void remove_multiples_of_others(std::vector<int> &xs) {
    xs.erase(std::remove_if(xs.begin(), xs.end(),
                            [xs_copy = xs](const int x) {
                                return std::any_of(
                                    xs_copy.cbegin(), xs_copy.cend(),
                                    [x](const int y) {
                                        return x % y == 0 && x / y > 1;
                                    });
                            }),
             xs.end());
}

void dedupe(std::vector<int> &xs) {
    std::sort(xs.begin(), xs.end());
    xs.erase(std::unique(xs.begin(), xs.end()), xs.end());
}

std::vector<std::vector<int>> non_empty_subsets(const std::vector<int> &xs) {
    std::vector<std::vector<int>> ans;

    for (int bits = 1; bits != (1 << xs.size()); ++bits) {
        std::vector<int> subset;
        for (auto i = 0; i != static_cast<int>(xs.size()); ++i)
            if (bits & (1 << i)) subset.push_back(xs[i]);

        ans.push_back(subset);
    }

    return ans;
}
} // namespace

namespace sum_of_multiples {
int to(std::vector<int> xs, const int upper_bound) {
    dedupe(xs);
    remove_multiples_of_others(xs);

    std::unordered_set<int> products;

    for (const auto &basis : non_empty_subsets(xs)) {
        const int p = std::accumulate(basis.cbegin(), basis.cend(), 1,
                                      std::multiplies<int>());

        for (int factor = 1; factor * p < upper_bound; ++factor)
            products.insert(factor * p);
    }

    return std::accumulate(products.cbegin(), products.cend(), 0);
}
} // namespace sum_of_multiples
