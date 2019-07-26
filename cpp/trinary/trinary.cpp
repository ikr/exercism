#include "trinary.h"

namespace trinary {
int to_decimal(const std::string &tri) {
    int significance = 1;
    int ans = 0;

    for (auto it = tri.crbegin(); it != tri.crend(); ++it) {
        if (*it < '0' || *it > '9') continue;
        ans += (*it - '0') * significance;
        significance *= 3;
    }

    return ans;
}
} // namespace trinary
