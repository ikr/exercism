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
        throw std::domain_error("Window size x must be: 0 < x <= src_sz");

    const vec ds = digits(source);
    vvec answer(ds.size());

    std::transform(ds.cbegin(), ds.cend(), answer.begin(),
                   [](const int d) { return vec{d}; });

    return answer;
}

} // namespace series
