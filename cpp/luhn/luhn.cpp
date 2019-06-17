#include "luhn.h"
#include <algorithm>
#include <locale>

namespace {
int double_capped(const int x) {
    const int xx = x * 2;
    return xx < 10 ? xx : (xx - 9);
}
} // namespace

namespace luhn {
bool valid(std::string num) {
    static std::locale loc;

    num.erase(std::copy_if(num.begin(), num.end(), num.begin(),
                           [](const char c) { return c != ' '; }),
              num.end());

    if (num.size() < 2 ||
        !std::all_of(num.begin(), num.end(),
                     [](const char c) { return std::isdigit(c, loc); }))
        return false;

    int sum = 0;
    for (size_t i = num.size(); i-- != 0;) {
        const int digit = num[i] - '0';
        const bool odd_offset = (num.size() - 1 - i) % 2;

        sum += odd_offset ? double_capped(digit) : digit;
    }

    return !(sum % 10);
}
} // namespace luhn
