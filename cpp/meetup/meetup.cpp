#include "meetup.h"

namespace {
const boost::gregorian::date_duration one_day{1};

boost::gregorian::date firsteenth(const boost::gregorian::greg_month &month,
                                  const unsigned int year) {
    return boost::gregorian::date{year, month, 13};
}

boost::gregorian::date first_day(const boost::gregorian::greg_month &month,
                                 const unsigned int year) {
    return boost::gregorian::date{year, month, 1};
}

boost::gregorian::date
closest_nth_weekday_day(const boost::gregorian::date &first,
                        const boost::gregorian::greg_weekday &day_of_week,
                        const unsigned int n) {
    boost::gregorian::date day{first};
    while (day.day_of_week() != day_of_week) day = day + one_day;
    day = day + boost::gregorian::date_duration{7 * (n - 1)};
    return day;
}

boost::gregorian::date
last_weeekday_day(const boost::gregorian::greg_month &month,
                  const unsigned int year,
                  const boost::gregorian::greg_weekday &day_of_week) {
    boost::gregorian::date day{first_day(month, year).end_of_month()};
    while (day.day_of_week() != day_of_week) day = day - one_day;
    return day;
}
} // namespace

namespace meetup {
scheduler::scheduler(const boost::gregorian::greg_month &month,
                     const unsigned int year)
    : m_month(month), m_year(year) {}

boost::gregorian::date scheduler::monteenth() const {
    return closest_nth_weekday_day(firsteenth(m_month, m_year),
                                   boost::gregorian::Monday, 1);
}

boost::gregorian::date scheduler::tuesteenth() const {
    return closest_nth_weekday_day(firsteenth(m_month, m_year),
                                   boost::gregorian::Tuesday, 1);
}

boost::gregorian::date scheduler::wednesteenth() const {
    return closest_nth_weekday_day(firsteenth(m_month, m_year),
                                   boost::gregorian::Wednesday, 1);
}

boost::gregorian::date scheduler::thursteenth() const {
    return closest_nth_weekday_day(firsteenth(m_month, m_year),
                                   boost::gregorian::Thursday, 1);
}

boost::gregorian::date scheduler::friteenth() const {
    return closest_nth_weekday_day(firsteenth(m_month, m_year),
                                   boost::gregorian::Friday, 1);
}

boost::gregorian::date scheduler::saturteenth() const {
    return closest_nth_weekday_day(firsteenth(m_month, m_year),
                                   boost::gregorian::Saturday, 1);
}

boost::gregorian::date scheduler::sunteenth() const {
    return closest_nth_weekday_day(firsteenth(m_month, m_year),
                                   boost::gregorian::Sunday, 1);
}

boost::gregorian::date scheduler::first_monday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Monday, 1);
}

boost::gregorian::date scheduler::first_tuesday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Tuesday, 1);
}

boost::gregorian::date scheduler::first_wednesday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Wednesday, 1);
}

boost::gregorian::date scheduler::first_thursday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Thursday, 1);
}

boost::gregorian::date scheduler::first_friday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Friday, 1);
}

boost::gregorian::date scheduler::first_saturday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Saturday, 1);
}

boost::gregorian::date scheduler::first_sunday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Sunday, 1);
}

boost::gregorian::date scheduler::second_monday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Monday, 2);
}

boost::gregorian::date scheduler::second_tuesday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Tuesday, 2);
}

boost::gregorian::date scheduler::second_wednesday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Wednesday, 2);
}

boost::gregorian::date scheduler::second_thursday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Thursday, 2);
}

boost::gregorian::date scheduler::second_friday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Friday, 2);
}

boost::gregorian::date scheduler::second_saturday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Saturday, 2);
}

boost::gregorian::date scheduler::second_sunday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Sunday, 2);
}

boost::gregorian::date scheduler::third_monday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Monday, 3);
}

boost::gregorian::date scheduler::third_tuesday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Tuesday, 3);
}

boost::gregorian::date scheduler::third_wednesday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Wednesday, 3);
}

boost::gregorian::date scheduler::third_thursday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Thursday, 3);
}

boost::gregorian::date scheduler::third_friday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Friday, 3);
}

boost::gregorian::date scheduler::third_saturday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Saturday, 3);
}

boost::gregorian::date scheduler::third_sunday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Sunday, 3);
}

boost::gregorian::date scheduler::fourth_monday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Monday, 4);
}

boost::gregorian::date scheduler::fourth_tuesday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Tuesday, 4);
}

boost::gregorian::date scheduler::fourth_wednesday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Wednesday, 4);
}

boost::gregorian::date scheduler::fourth_thursday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Thursday, 4);
}

boost::gregorian::date scheduler::fourth_friday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Friday, 4);
}

boost::gregorian::date scheduler::fourth_saturday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Saturday, 4);
}

boost::gregorian::date scheduler::fourth_sunday() const {
    return closest_nth_weekday_day(first_day(m_month, m_year),
                                   boost::gregorian::Sunday, 4);
}

boost::gregorian::date scheduler::last_monday() const {
    return last_weeekday_day(m_month, m_year, boost::gregorian::Monday);
}

boost::gregorian::date scheduler::last_tuesday() const {
    return last_weeekday_day(m_month, m_year, boost::gregorian::Tuesday);
}

boost::gregorian::date scheduler::last_wednesday() const {
    return last_weeekday_day(m_month, m_year, boost::gregorian::Wednesday);
}

boost::gregorian::date scheduler::last_thursday() const {
    return last_weeekday_day(m_month, m_year, boost::gregorian::Thursday);
}

boost::gregorian::date scheduler::last_friday() const {
    return last_weeekday_day(m_month, m_year, boost::gregorian::Friday);
}

boost::gregorian::date scheduler::last_saturday() const {
    return last_weeekday_day(m_month, m_year, boost::gregorian::Saturday);
}

boost::gregorian::date scheduler::last_sunday() const {
    return last_weeekday_day(m_month, m_year, boost::gregorian::Sunday);
}
} // namespace meetup
