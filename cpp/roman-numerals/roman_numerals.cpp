#include "roman_numerals.h"
#include <cassert>
#include <iterator>
#include <map>

namespace {
static const std::map<int, std::string> symbols_by_value{
    {1, "I"},   {4, "IV"},   {5, "V"},   {9, "IX"},  {10, "X"},
    {40, "XL"}, {50, "L"},   {90, "XC"}, {100, "C"}, {400, "CD"},
    {500, "D"}, {900, "CM"}, {1000, "M"}};

struct Numeral final {
    const int value;
    const std::string symbol;
};

Numeral max_divider(const int n) {
    const auto lbound = symbols_by_value.lower_bound(n);

    if (lbound == symbols_by_value.cend())
        return {symbols_by_value.crbegin()->first,
                symbols_by_value.crbegin()->second};

    if (lbound->first == n) return {lbound->first, lbound->second};
    return {std::prev(lbound)->first, std::prev(lbound)->second};
}
} // namespace

namespace roman_numerals {
std::string convert(int n) {
    assert(n > 0);
    std::string answer;

    while (n) {
        const auto d = max_divider(n);
        answer += d.symbol;
        n -= d.value;
    }

    return answer;
}
} // namespace roman_numerals
