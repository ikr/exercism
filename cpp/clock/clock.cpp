#include "clock.h"

namespace date_independent {
namespace clock {
std::string at(const int hour, const int minute) {
    return std::to_string(hour) + ":" + std::to_string(minute);
}
} // namespace clock
} // namespace date_independent
