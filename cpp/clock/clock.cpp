#include "clock.h"
#include <iomanip>
#include <sstream>

namespace {
constexpr int positive_mod(const int divider, const int x) {
    return (x % divider + divider) % divider;
}
} // namespace

namespace date_independent {
namespace clock {
std::string at(const int hours, const int minutes) {
    const int h =
        positive_mod(24, hours + minutes / 60) - (minutes % 60 < 0 ? 1 : 0);

    const int m = positive_mod(60, minutes);

    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << h << ':' << std::setfill('0')
       << std::setw(2) << m;
    return ss.str();
}
} // namespace clock
} // namespace date_independent
