#include "robot_name.h"
#include <random>

namespace {

std::mt19937 random_generator{std::random_device{}()};

std::string random_sequence(std::uniform_int_distribution<short> &distribution,
                            const size_t length) {
    std::string result(length, ' ');

    for (size_t i = 0; i != length; ++i) {
        result[i] = static_cast<char>(distribution(random_generator));
    }

    return result;
}

} // namespace

namespace robot_name {

std::unordered_set<std::string> robot::all_ids;

robot::robot() : id{new_id()} {}
robot::~robot() { all_ids.erase(id); }

void robot::reset() {
    all_ids.erase(id);
    id = new_id();
}

std::string robot::new_id() {
    auto letters_dist = std::uniform_int_distribution<short>{'A', 'Z'};
    auto digits_dist = std::uniform_int_distribution<short>{'0', '9'};

    auto result = random_sequence(letters_dist, name_letters_count) +
                  random_sequence(digits_dist, name_digits_count);

    if (all_ids.count(result))
        return new_id();

    all_ids.insert(result);
    return result;
}

} // namespace robot_name
