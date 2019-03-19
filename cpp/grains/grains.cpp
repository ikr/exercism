#include "grains.h"
#include <cassert>
#include <cmath>

long grains::square(const int num) {
    static long cache[MAX_SQUARE_NUM + 1]{};
    assert(num >= 1 && num <= MAX_SQUARE_NUM);

    if (!cache[num])
        cache[num] = std::pow(2, num - 1);

    return cache[num];
}

long grains::total() {
    long result{0};

    for (int i = 1; i <= MAX_SQUARE_NUM; ++i)
        result += square(i);

    return result;
}
