#include "robot_simulator.h"

namespace {
using robot_simulator::Bearing;
using robot_simulator::XY;

Bearing bearing_add(const Bearing bearing, const int delta) {
    return static_cast<Bearing>((static_cast<int>(bearing) + delta + 4) % 4);
}

XY operator+(const XY a, const XY b) {
    return {a.first + b.first, a.second + b.second};
}

XY advance_delta(const Bearing bearing) {
    switch (bearing) {
    case Bearing::NORTH:
        return {0, 1};

    case Bearing::EAST:
        return {1, 0};

    case Bearing::SOUTH:
        return {0, -1};

    case Bearing::WEST:
        return {-1, 0};
    }
}
} // namespace

namespace robot_simulator {
Robot::Robot() : m_position{0, 0}, m_bearing{Bearing::NORTH} {}

Robot::Robot(XY position, Bearing bearing)
    : m_position(position), m_bearing(bearing) {}

XY Robot::get_position() const { return m_position; }

Bearing Robot::get_bearing() const { return m_bearing; }

void Robot::turn_right() { m_bearing = bearing_add(m_bearing, 1); }

void Robot::turn_left() { m_bearing = bearing_add(m_bearing, -1); }

void Robot::advance() { m_position = m_position + advance_delta(m_bearing); }

void Robot::execute_sequence(const std::string &seq) {
    for (const char command : seq) {
        switch (command) {
        case 'R':
            turn_right();
            break;

        case 'L':
            turn_left();
            break;

        case 'A':
            advance();
            break;
        }
    }
}
} // namespace robot_simulator
