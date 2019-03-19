#include "grains.h"
#include <cassert>
#include <cmath>

long fast_exponent_of_2(const int power) {
    static long cache[grains::MAX_SQUARE_NUM]{1};
    assert(power >= 0 && power < grains::MAX_SQUARE_NUM);

    if (!cache[power]) {
        const long value_on_half = fast_exponent_of_2(power / 2);

        if (power % 2)
            cache[power] = 2 * value_on_half * value_on_half;
        else
            cache[power] = value_on_half * value_on_half;
    }

    return cache[power];
}

long grains::square(const int num) {
    return fast_exponent_of_2(num - 1);
}

long grains::total() {
    return 2 * fast_exponent_of_2(MAX_SQUARE_NUM - 1) - 1;
}
