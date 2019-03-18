#ifndef SPACE_AGE_H
#define SPACE_AGE_H

namespace space_age {
struct space_age {
    explicit constexpr space_age(const double age_in_seconds_)
        : age_in_seconds(age_in_seconds_){};

    constexpr double seconds() const { return age_in_seconds; }

    constexpr double on_earth() const {
        return age_in_seconds / earth_year_seconds;
    }

    constexpr double on_jupiter() const {
        return on_earth() / orbital_period_in_earth_years::jupiter;
    }

    constexpr double on_mars() const {
        return on_earth() / orbital_period_in_earth_years::mars;
    }

    constexpr double on_mercury() const {
        return on_earth() / orbital_period_in_earth_years::mercury;
    }

    constexpr double on_neptune() const {
        return on_earth() / orbital_period_in_earth_years::neptune;
    }

    constexpr double on_saturn() const {
        return on_earth() / orbital_period_in_earth_years::saturn;
    }

    constexpr double on_uranus() const {
        return on_earth() / orbital_period_in_earth_years::uranus;
    }

    constexpr double on_venus() const {
        return on_earth() / orbital_period_in_earth_years::venus;
    }

  private:
    const double age_in_seconds;
    static constexpr double earth_year_seconds = 31557600;

    struct orbital_period_in_earth_years {
        static constexpr double jupiter = 11.862615;
        static constexpr double mars = 1.8808158;
        static constexpr double mercury = 0.2408467;
        static constexpr double neptune = 164.79132;
        static constexpr double saturn = 29.447498;
        static constexpr double uranus = 84.016846;
        static constexpr double venus = 0.61519726;
    };
};
} // namespace space_age

#endif // SPACE_AGE_H
