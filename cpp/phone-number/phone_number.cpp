#include "phone_number.h"
#include <locale>
#include <numeric>

namespace {
std::string digits(const std::string &source) {
    return std::accumulate(source.cbegin(), source.cend(), std::string{""},
                           [](std::string agg, const char c) {
                               if (std::isdigit(c, std::locale::classic()))
                                   agg.append(1, c);
                               return agg;
                           });
}
} // namespace

namespace phone_number {
phone_number::phone_number(const std::string &source)
    : m_digits{digits(source)} {}

std::string phone_number::number() const { return m_digits; }
} // namespace phone_number
