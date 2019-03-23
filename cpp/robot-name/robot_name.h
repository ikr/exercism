#ifndef ROBOT_NAME_H
#define ROBOT_NAME_H
#include <string>
#include <random>

namespace robot_name {
struct robot {
    robot();
    std::string name() const { return id; }
    void reset();

  private:
    std::string id;

  static std::random_device& provide_random_device();
  static std::mt19937 engine;
};
} // namespace robot_name

#endif //ROBOT_NAME_H
