#ifndef DIFFERENCE_OF_SQUARES_H
#define DIFFERENCE_OF_SQUARES_H

/**
 * See http://mathworld.wolfram.com/FaulhabersFormula.html
 */
namespace squares {
constexpr int square_of_sum(const int x) {
    return (x * x + x) * (x * x + x) / 4;
}

constexpr int sum_of_squares(const int x) {
    return (2 * x * x * x + 3 * x * x + x) / 6;
}

constexpr int difference(const int x) {
    return square_of_sum(x) - sum_of_squares(x);
}
} // namespace squares

#endif // DIFFERENCE_OF_SQUARES_H
