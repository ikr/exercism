#include "space_age.h"

namespace space_age {
space_age::space_age(const int age_in_seconds_)
    : age_in_seconds(age_in_seconds_) {}

int space_age::seconds() const { return age_in_seconds; }
} // namespace space_age
