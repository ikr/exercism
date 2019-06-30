#ifndef DIFFERENCE_OF_SQUARES_H
#define DIFFERENCE_OF_SQUARES_H
namespace squares {
int square_of_sum(const int x) {
    const int sqrt = (x * x + x) / 2;
    return sqrt * sqrt;
}

/**
 * See http://mathworld.wolfram.com/FaulhabersFormula.html
 */
int sum_of_squares(const int x) {
    const int x_2 = x * x;
    return (2 * x_2 * x + 3 * x_2 + x) / 6;
}

int difference(const int x) { return square_of_sum(x) - sum_of_squares(x); }
} // namespace squares

#endif // DIFFERENCE_OF_SQUARES_H
