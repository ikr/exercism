#include "meetup.h"

namespace {
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
    : m_firsteenth(year, month, 13) {}

boost::gregorian::date scheduler::monteenth() const {
    return teenth(m_firsteenth, boost::gregorian::Monday);
}

boost::gregorian::date scheduler::tuesteenth() const {
    return teenth(m_firsteenth, boost::gregorian::Tuesday);
}
} // namespace meetup
