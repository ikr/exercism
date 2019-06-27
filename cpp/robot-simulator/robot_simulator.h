#ifndef ROBOT_SIMULATOR_H
#define ROBOT_SIMULATOR_H
#include <string>
#include <utility>

namespace robot_simulator {
enum class Bearing { NORTH, EAST, SOUTH, WEST };
using RowCol = std::pair<int, int>;

struct Robot {
    Robot();
    Robot(RowCol position, Bearing bearing);

    RowCol get_position() const;
    Bearing get_bearing() const;

    void turn_right();
    void turn_left();
    void advance();
    void execute_sequence(const std::string &seq);

  private:
    RowCol m_position;
    Bearing m_bearing;
};
} // namespace robot_simulator

#endif // ROBOT_SIMULATOR_H
