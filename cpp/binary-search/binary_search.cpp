#include "binary_search.h"
#include <stdexcept>

namespace binary_search {

int find(const std::vector<int> &haystack, const int needle) {
    if (!haystack.size() || needle < haystack[0] || needle > haystack.back())
        throw std::domain_error{"The needle can't possibly be inside"};

    int begin = 0;
    int end = haystack.size();
    for (;;) {
        const int sz = end - begin;

        if (sz == 1) {
            if (needle == haystack[begin])
                return begin;
            else
                throw std::domain_error{"Needle not found"};
        }

        const int mid = begin + sz / 2 + (sz % 2 ? 1 : 0);

        if (haystack[mid] <= needle)
            begin = mid;
        else
            end = mid;
    }
}

} // namespace binary_search
