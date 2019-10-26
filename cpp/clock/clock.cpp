#include "clock.h"
#include <iomanip>
#include <sstream>

namespace {
constexpr int positive_mod(const int divider, const int x) {
    return (x % divider + divider) % divider;
}
} // namespace

namespace date_independent {
Time::Time(const int minutes) : m_minutes(minutes) {}

Time::operator std::string() const {
    const int h = m_minutes / 60 % 24;
    const int m = m_minutes % 60;

    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << h << ':' << std::setfill('0')
       << std::setw(2) << m;
    return ss.str();
}

Time Time::plus(const int minutes) const {
    return clock::at(0, m_minutes + minutes);
}

namespace clock {
Time at(const int hours, const int minutes) {
    const int h =
        positive_mod(24, hours + minutes / 60) - (minutes % 60 < 0 ? 1 : 0);
    const int m = positive_mod(60, minutes);
    return Time{h * 60 + m};
}
} // namespace clock
} // namespace date_independent
