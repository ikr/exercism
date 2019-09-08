#include "meetup.h"

namespace {
boost::gregorian::date firsteenth(const boost::gregorian::greg_month &month,
                                  const unsigned int year) {
    return boost::gregorian::date{year, month, 13};
}

boost::gregorian::date teenth(const boost::gregorian::date &firsteenth,
                              const boost::gregorian::greg_weekday &dow) {
    boost::gregorian::date day{firsteenth};
    while (day.day_of_week() != dow)
        day = day + boost::gregorian::date_duration{1};
    return day;
}
} // namespace

namespace meetup {
scheduler::scheduler(const boost::gregorian::greg_month &month,
                     const unsigned int year)
    : m_month(month), m_year(year) {}

boost::gregorian::date scheduler::monteenth() const {
    return teenth(firsteenth(m_month, m_year), boost::gregorian::Monday);
}

boost::gregorian::date scheduler::tuesteenth() const {
    return teenth(firsteenth(m_month, m_year), boost::gregorian::Tuesday);
}

boost::gregorian::date scheduler::wednesteenth() const {
    return teenth(firsteenth(m_month, m_year), boost::gregorian::Wednesday);
}

boost::gregorian::date scheduler::thursteenth() const {
    return teenth(firsteenth(m_month, m_year), boost::gregorian::Thursday);
}

boost::gregorian::date scheduler::friteenth() const {
    return teenth(firsteenth(m_month, m_year), boost::gregorian::Friday);
}

boost::gregorian::date scheduler::saturteenth() const {
    return teenth(firsteenth(m_month, m_year), boost::gregorian::Saturday);
}

boost::gregorian::date scheduler::sunteenth() const {
    return teenth(firsteenth(m_month, m_year), boost::gregorian::Sunday);
}
} // namespace meetup
