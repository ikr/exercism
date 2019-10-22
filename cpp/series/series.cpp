#include "series.h"
#include <algorithm>
#include <stdexcept>

namespace {
using vec = std::vector<int>;
using vvec = std::vector<vec>;
} // namespace

namespace series {
vec digits(const std::string &source) {
    vec answer(source.size());
    std::transform(source.cbegin(), source.cend(), answer.begin(),
                   [](const char d) { return d - '0'; });
    return answer;
}

vvec slice(const std::string &source, const int window_size) {
    if (window_size <= 0 || window_size > static_cast<int>(source.size()))
        throw std::domain_error("Expected: 0 < window_size <= source_size");

    const vec ds = digits(source);
    vvec answer;

    for (auto first = ds.cbegin(), last = first + window_size;;
         ++first, ++last) {
        answer.push_back(vec{first, last});
        if (last == ds.cend()) break;
    }

    return answer;
}
} // namespace series
