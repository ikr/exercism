#include "binary.h"

namespace binary {
unsigned int convert(const std::string &bin_num) {
    unsigned int multiplier = 1;
    unsigned int answer = 0;

    for (auto it = bin_num.crbegin(); it != bin_num.crend(); ++it) {
        if (*it == '1')
            answer += multiplier;
        else if (*it != '0')
            return 0;

        multiplier *= 2;
    }

    return answer;
}
} // namespace binary
