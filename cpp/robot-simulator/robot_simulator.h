#ifndef ROBOT_SIMULATOR_H
#define ROBOT_SIMULATOR_H
#include <utility>

namespace robot_simulator {
enum class Bearing { NORTH };

struct Robot {
    std::pair<int, int> get_position() const;
    Bearing get_bearing() const;
};
} // namespace robot_simulator

#endif // ROBOT_SIMULATOR_H
