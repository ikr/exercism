#include "robot_name.h"

namespace robot_name {

std::unordered_set<std::string> robot::all_ids;

robot::robot() : id{new_id()} {}
robot::~robot() { all_ids.erase(id); }

void robot::reset() {
    all_ids.erase(id);
    id = new_id();
}

std::string robot::new_id() {
    auto result =
        random_sequence(provide_letters_distribution(), name_letters_count) +
        random_sequence(provide_digits_distribution(), name_digits_count);

    if (all_ids.count(result))
        return new_id();

    all_ids.insert(result);
    return result;
}

std::string
robot::random_sequence(std::uniform_int_distribution<short> &distribution,
                       const size_t length) {
    std::string result(length, ' ');

    for (size_t i = 0; i != length; ++i) {
        result[i] = static_cast<char>(distribution(provide_random_generator()));
    }

    return result;
}

std::random_device &robot::provide_random_device() {
    static std::random_device result;
    return result;
}

std::mt19937 &robot::provide_random_generator() {
    static std::mt19937 result{provide_random_device()()};
    return result;
}

std::uniform_int_distribution<short> &robot::provide_letters_distribution() {
    static std::uniform_int_distribution<short> result{'A', 'Z'};
    return result;
}

std::uniform_int_distribution<short> &robot::provide_digits_distribution() {
    static std::uniform_int_distribution<short> result{'0', '9'};
    return result;
}

} // namespace robot_name
