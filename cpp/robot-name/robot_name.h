#ifndef ROBOT_NAME_H
#define ROBOT_NAME_H
#include <string>

namespace robot_name {
struct robot {
    robot();
    std::string name() const { return id; }
    void reset();

  private:
    std::string id;
};
} // namespace robot_name

#endif //ROBOT_NAME_H
