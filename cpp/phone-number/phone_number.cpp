#include "phone_number.h"
#include <algorithm>
#include <locale>
#include <sstream>
#include <stdexcept>

namespace {
std::string digits(std::string source) {
    source.erase(std::remove_if(source.begin(), source.end(),
                                [](const char c) {
                                    return !std::isdigit(
                                        c, std::locale::classic());
                                }),
                 source.end());

    return source;
}

std::string drop_country_code(std::string digits) {
    if (digits.size() == 11 && digits[0] == '1') digits.erase(digits.cbegin());
    return digits;
}

std::string exchange_code(const std::string &digits) {
    return digits.substr(3, 3);
}

std::string subscriber_number(const std::string &digits) {
    return digits.substr(6);
}

bool is_at_least_2(const char digit) { return digit != '0' && digit != '1'; }
} // namespace

namespace phone_number {
phone_number::phone_number(const std::string &source)
    : m_digits{drop_country_code(digits(source))} {
    if (m_digits.size() != 10 || !is_at_least_2(area_code()[0]) ||
        !is_at_least_2(exchange_code(m_digits)[0]))
        throw std::domain_error("Wrong format");
}

std::string phone_number::number() const { return m_digits; }
std::string phone_number::area_code() const { return m_digits.substr(0, 3); }

phone_number::operator std::string() const {
    std::stringstream ss;

    ss << '(' << area_code() << ')' << ' ' << exchange_code(m_digits) << '-'
       << subscriber_number(m_digits);

    return ss.str();
}
} // namespace phone_number
