#include "meetup.h"

namespace meetup {
scheduler::scheduler(const boost::gregorian::greg_month month,
                     const unsigned int year)
    : m_firsteen(year, month, 13) {}

boost::gregorian::date scheduler::monteenth() const {
    boost::gregorian::date day{m_firsteen};
    while (day.day_of_week() != boost::gregorian::Monday)
        day = day + boost::gregorian::date_duration{1};
    return day;
}
} // namespace meetup
