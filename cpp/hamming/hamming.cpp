#include "hamming.h"
#include <stdexcept>

namespace hamming {

int compute(const std::string &xs, const std::string &ys) {
    if (xs.size() != ys.size())
        throw std::domain_error{"Sequences of equal length expected"};

    int result = 0;

    for (auto i = xs.begin(), j = ys.begin(); i != xs.end(); ++i, ++j) {
        if (*i != *j) ++result;
    }

    return result;
}

} // namespace hamming
