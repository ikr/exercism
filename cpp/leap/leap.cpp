#include "leap.h"

bool leap::is_leap_year(int x) {
    return (x % 4 == 0)  && !(x % 100 == 0 && x % 400 != 0);
}
