#include "triangle.h"
#include <stdexcept>

namespace triangle {
flavor kind(const double a, const double b, const double c) {
    if (a + b <= c || a + c <= b || b + c <= a)
        throw std::domain_error("Not a triangle");

    if (a == b && b == c)
        return flavor::equilateral;

    if (a == b || a == c || b == c)
        return flavor::isosceles;

    return flavor::scalene;
}
} // namespace triangle
