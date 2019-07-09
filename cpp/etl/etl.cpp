#include "etl.h"
#include <locale>

namespace {
const std::locale &locale() {
    static std::locale l{};
    return l;
}

char to_lower(const char c) { return std::tolower(c, locale()); }
} // namespace

namespace etl {
std::map<char, int> transform(const std::map<int, std::vector<char>> &old) {
    return {};
}
} // namespace etl
