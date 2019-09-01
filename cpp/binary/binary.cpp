#include "binary.h"

namespace binary {
unsigned int convert(const std::string &bin_num) {
    unsigned int answer = 0;

    for (const char digit : bin_num) {
        answer *= 2;

        if (digit == '1')
            ++answer;
        else if (digit != '0')
            return 0;
    }

    return answer;
}
} // namespace binary
