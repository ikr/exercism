#ifndef ROBOT_NAME_H
#define ROBOT_NAME_H
#include <string>
#include <unordered_set>

namespace robot_name {
struct robot {
    robot();
    ~robot();
    robot(const robot &) = delete;
    robot &operator=(const robot &) = delete;

    const std::string& name() const { return id; }
    void reset();

  private:
    std::string id;
    static std::unordered_set<std::string> all_ids;

    static constexpr size_t name_letters_count = 2;
    static constexpr size_t name_digits_count = 3;

    static std::string new_id();
};
} // namespace robot_name

#endif // ROBOT_NAME_H
