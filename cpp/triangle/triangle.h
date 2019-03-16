#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <stdexcept>

namespace triangle {
enum class flavor { equilateral, isosceles, scalene };

constexpr flavor kind(const double a, const double b, const double c) {
    return a == b && b == c ? flavor::equilateral : flavor::scalene;
}

} // namespace triangle

#endif // TRIANGLE_H
