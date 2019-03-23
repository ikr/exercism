#include "raindrops.h"

namespace raindrops {

std::string convert(const int x) {
    std::string result;

    if (!(x % 3))
        result += "Pling";

    if (!(x % 5))
        result += "Plang";

    if (!(x % 7))
        result += "Plong";

    return result.empty() ? std::to_string(x) : result;
}

} // namespace raindrops
