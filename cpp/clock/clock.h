#if !defined(CLOCK_H)
#define CLOCK_H

#include <string>

namespace date_independent {

struct Time final {
    explicit Time(const int normalized_total_minutes);
    explicit operator std::string() const;
    Time plus(const int minutes) const;
    bool operator==(const Time &t) const;
    bool operator!=(const Time &t) const;

  private:
    const int m_minutes;
};

namespace clock {
Time at(const int hours, const int minutes);
} // namespace clock
} // namespace date_independent

#endif // CLOCK_H
