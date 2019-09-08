#ifndef MEETUP_H
#define MEETUP_H

#include <boost/date_time/gregorian/gregorian.hpp>

namespace meetup {
struct scheduler final {
    scheduler(const boost::gregorian::greg_month &month,
              const unsigned int year);

    boost::gregorian::date monteenth() const;
    boost::gregorian::date tuesteenth() const;

  private:
    const boost::gregorian::date m_firsteenth;
};
} // namespace meetup

#endif // MEETUP_H
