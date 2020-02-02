#include "two_fer.h"

namespace two_fer {
std::string two_fer() { return two_fer("you"); }

std::string two_fer(const std::string &name) {
    std::string answer{"One for "};
    answer += name;
    answer += ", one for me.";

    return answer;
}
} // namespace two_fer
