#include "meetup.h"

namespace {
boost::gregorian::date firsteenth(const boost::gregorian::greg_month &month,
                                  const unsigned int year) {
    return boost::gregorian::date{year, month, 13};
}

boost::gregorian::date first_day(const boost::gregorian::greg_month &month,
                                 const unsigned int year) {
    return boost::gregorian::date{year, month, 1};
}

boost::gregorian::date
closest_weekday_day(const boost::gregorian::date &first,
                    const boost::gregorian::greg_weekday &day_of_week) {
    boost::gregorian::date day{first};
    while (day.day_of_week() != day_of_week)
        day = day + boost::gregorian::date_duration{1};
    return day;
}
} // namespace

namespace meetup {
scheduler::scheduler(const boost::gregorian::greg_month &month,
                     const unsigned int year)
    : m_month(month), m_year(year) {}

boost::gregorian::date scheduler::monteenth() const {
    return closest_weekday_day(firsteenth(m_month, m_year),
                               boost::gregorian::Monday);
}

boost::gregorian::date scheduler::tuesteenth() const {
    return closest_weekday_day(firsteenth(m_month, m_year),
                               boost::gregorian::Tuesday);
}

boost::gregorian::date scheduler::wednesteenth() const {
    return closest_weekday_day(firsteenth(m_month, m_year),
                               boost::gregorian::Wednesday);
}

boost::gregorian::date scheduler::thursteenth() const {
    return closest_weekday_day(firsteenth(m_month, m_year),
                               boost::gregorian::Thursday);
}

boost::gregorian::date scheduler::friteenth() const {
    return closest_weekday_day(firsteenth(m_month, m_year),
                               boost::gregorian::Friday);
}

boost::gregorian::date scheduler::saturteenth() const {
    return closest_weekday_day(firsteenth(m_month, m_year),
                               boost::gregorian::Saturday);
}

boost::gregorian::date scheduler::sunteenth() const {
    return closest_weekday_day(firsteenth(m_month, m_year),
                               boost::gregorian::Sunday);
}

boost::gregorian::date scheduler::first_monday() const {
    return closest_weekday_day(first_day(m_month, m_year),
                               boost::gregorian::Monday);
}
} // namespace meetup
