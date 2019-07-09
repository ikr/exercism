#include "etl.h"
#include <locale>

namespace etl {
std::map<char, int> transform(const std::map<int, std::vector<char>> &old) {
    static std::locale loc{};
    std::map<char, int> ans;

    for (const auto kv : old) {
        for (const auto &v : kv.second) {
            ans[std::tolower(v, loc)] = kv.first;
        }
    }

    return ans;
}
} // namespace etl
