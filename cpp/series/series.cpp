#include "series.h"
#include <algorithm>
#include <stdexcept>

namespace series {
std::vector<int> digits(const std::string &source) {
    std::vector<int> answer(source.size());
    std::transform(source.cbegin(), source.cend(), answer.begin(),
                   [](const char d) { return d - '0'; });
    return answer;
}

std::vector<std::vector<int>> slice(const std::string &source,
                                    const int window_size) {
    if (window_size <= 0 || window_size > static_cast<int>(source.size()))
        throw std::domain_error("Expected: 0 < window_size <= source_size");

    std::vector<std::vector<int>> answer;

    for (auto first = source.cbegin(), last = first + window_size;;
         ++first, ++last) {
        answer.push_back(digits(std::string(first, last)));
        if (last == source.cend()) break;
    }

    return answer;
}
} // namespace series
