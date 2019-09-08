#include "meetup.h"
#include <cassert>

namespace meetup {
scheduler::scheduler(const boost::gregorian::greg_month month,
                     const unsigned int year)
    : m_month(month), m_year(year) {}

boost::gregorian::date scheduler::monteenth() const {
    assert(m_year > 0U);
    return boost::gregorian::date{};
}
} // namespace meetup
