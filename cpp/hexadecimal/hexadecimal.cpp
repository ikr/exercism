#include "hexadecimal.h"

namespace {
constexpr unsigned int decimal_value(const char hex_digit) {
    if ('a' <= hex_digit && hex_digit <= 'f') return 10U + hex_digit - 'a';
    if ('0' <= hex_digit && hex_digit <= '9') return hex_digit - '0';
    return 0U;
}
} // namespace

namespace hexadecimal {
unsigned int convert(const std::string &hex_literal) {
    unsigned int answer = 0U;

    for (const auto hex_digit : hex_literal) {
        if (hex_digit != '0' && !decimal_value(hex_digit)) return 0U;
        answer = answer * 16U + decimal_value(hex_digit);
    }

    return answer;
}
} // namespace hexadecimal
