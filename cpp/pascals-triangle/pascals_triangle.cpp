#include "pascals_triangle.h"

namespace {
using Vec = std::vector<int>;
using VVec = std::vector<Vec>;

Vec next_row(const Vec &row) {
    Vec ans(row.size() + 1, 1);

    for (auto it = row.cbegin(); it != row.cend(); ++it) {
        ans[distance(row.cbegin(), it)] =
            *it + (it == row.cbegin() ? 0 : *(it - 1));
    }

    return ans;
}
} // namespace

namespace pascals_triangle {
VVec generate_rows(unsigned int last_row_num) {
    VVec ans(last_row_num);

    for (unsigned int i = 0; i != last_row_num; ++i) {
        ans[i] = next_row(i ? ans[i - 1] : Vec{});
    }

    return ans;
}
} // namespace pascals_triangle
