#include "clock.h"
#include <cassert>
#include <iomanip>
#include <sstream>

namespace {
constexpr int positive_mod(const int divider, const int x) {
    return (x % divider + divider) % divider;
}
} // namespace

namespace date_independent {
Time::Time(const int normalized_total_minutes)
    : m_minutes(normalized_total_minutes) {
    assert(m_minutes >= 0);
}

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

bool Time::operator==(const Time &t) const { return m_minutes == t.m_minutes; }
bool Time::operator!=(const Time &t) const { return m_minutes != t.m_minutes; }

namespace clock {
Time at(const int hours, const int minutes) {
    const int h =
        positive_mod(24, hours + minutes / 60) - (minutes % 60 < 0 ? 1 : 0);
    const int m = positive_mod(60, minutes);
    const int total_minutes = h * 60 + m;
    return Time{total_minutes < 0 ? 24 * 60 + total_minutes : total_minutes};
}
} // namespace clock
} // namespace date_independent
