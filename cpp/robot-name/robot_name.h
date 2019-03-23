#ifndef ROBOT_NAME_H
#define ROBOT_NAME_H
#include <random>
#include <string>
#include <unordered_set>

namespace robot_name {
struct robot {
    robot();
    ~robot();
    std::string name() const { return id; }
    void reset();

  private:
    std::string id;
    static std::unordered_set<std::string> all_ids;

    static constexpr size_t name_letters_count = 2;
    static constexpr size_t name_digits_count = 3;

    robot(const robot &);
    robot &operator=(const robot &);

    static std::string new_id();

    static std::string
    random_sequence(std::uniform_int_distribution<short> &distribution,
                    const size_t length);

    static std::random_device &provide_random_device();
    static std::mt19937 &provide_random_generator();
    static std::uniform_int_distribution<short> &provide_letters_distribution();
    static std::uniform_int_distribution<short> &provide_digits_distribution();
};
} // namespace robot_name

#endif // ROBOT_NAME_H
