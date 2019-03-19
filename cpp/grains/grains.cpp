#include "grains.h"
#include <cassert>
#include <cmath>

long fast_exponent_of_2(const int power) {
    return 1L << power;
}

long grains::square(const int num) {
    return fast_exponent_of_2(num - 1);
}

long grains::total() {
    return 2 * fast_exponent_of_2(MAX_SQUARE_NUM - 1) - 1;
}
