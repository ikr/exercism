#include "grains.h"
#include <cassert>

long fast_exponent_of_2(const int power) {
    static long cache[grains::MAX_SQUARE_NUM]{1};

    if (!cache[power]) {
        const long value_on_half = fast_exponent_of_2(power / 2);

        if (power % 2) {
            cache[power] = 2 * value_on_half * value_on_half;
        } else {
            cache[power] = value_on_half * value_on_half;
        }
    }

    return cache[power];
}

long grains::square(const int num) {
    assert(num >= 1 && num <= MAX_SQUARE_NUM);
    return fast_exponent_of_2(num - 1);
}

long grains::total() {
    long result{0};

    for (int i = 1; i <= MAX_SQUARE_NUM; ++i)
        result += square(i);

    return result;
}
