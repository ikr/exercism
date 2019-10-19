#include "phone_number.h"
#include <algorithm>
#include <locale>

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
} // namespace

namespace phone_number {
phone_number::phone_number(const std::string &source)
    : m_digits{digits(source)} {}

std::string phone_number::number() const { return m_digits; }
} // namespace phone_number
