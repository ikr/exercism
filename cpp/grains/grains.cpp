#include "grains.h"
#include <cassert>
#include <climits>

grains::ulong fast_exponent_of_2(const grains::uint power) {
    assert(power < sizeof(grains::ulong) * CHAR_BIT);
    return 1ULL << power;
}

grains::ulong grains::square(const uint num) {
    return fast_exponent_of_2(num - 1);
}

grains::ulong grains::total() {
    return 2 * fast_exponent_of_2(MAX_SQUARE_NUM - 1) - 1;
}
