#include "series.h"
#include <algorithm>

namespace series {
std::vector<int> digits(const std::string &source) {
    std::vector<int> answer(source.size());
    std::transform(source.cbegin(), source.cend(), answer.begin(),
                   [](const char d) { return d - '0'; });
    return answer;
}
} // namespace series
