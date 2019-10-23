#include "clock.h"
#include <iomanip>
#include <sstream>

namespace date_independent {
namespace clock {
std::string at(const int hour, const int minute) {
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << (240 + hour + minute / 60) % 24
       << ':' << std::setfill('0') << std::setw(2) << ((6000 + minute) % 60);
    return ss.str();
}
} // namespace clock
} // namespace date_independent
