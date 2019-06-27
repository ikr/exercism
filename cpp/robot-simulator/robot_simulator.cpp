#include "robot_simulator.h"

namespace {
using RowCol = std::pair<int, int>;
}

namespace robot_simulator {
RowCol Robot::get_position() const { return {0, 0}; }

Bearing Robot::get_bearing() const { return Bearing::NORTH; }
} // namespace robot_simulator
