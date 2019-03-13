#ifndef SPACE_AGE_H
#define SPACE_AGE_H

namespace space_age {
struct space_age {
    space_age(const int age_in_seconds_);
    int seconds() const;
private:
  int age_in_seconds;
};
} // namespace space_age

#endif // SPACE_AGE_H
