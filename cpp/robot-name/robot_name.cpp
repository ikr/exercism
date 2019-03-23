#include "robot_name.h"

namespace robot_name {

robot::robot() : id{} {}

void robot::reset() {}

std::random_device &robot::provide_random_device() {
    static std::random_device r_dev;
    return r_dev;
}

std::mt19937 robot::engine{provide_random_device()()};

} // namespace robot_name
