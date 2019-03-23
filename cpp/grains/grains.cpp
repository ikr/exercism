#include "grains.h"
#include <cassert>
#include <climits>

unsigned long long fast_exponent_of_2(const unsigned char power) {
    assert(power < sizeof(unsigned long long) * CHAR_BIT);
    return 1ULL << power;
}

unsigned long long grains::square(const unsigned char num) {
    return fast_exponent_of_2(num - 1);
}

unsigned long long grains::total() {
    return 2 * fast_exponent_of_2(MAX_SQUARE_NUM - 1) - 1;
}
