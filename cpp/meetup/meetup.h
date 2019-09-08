#ifndef MEETUP_H
#define MEETUP_H

#include <boost/date_time/gregorian/gregorian.hpp>

namespace meetup {
struct scheduler final {
    scheduler(const boost::gregorian::greg_month &month,
              const unsigned int year);

    boost::gregorian::date monteenth() const;
    boost::gregorian::date tuesteenth() const;
    boost::gregorian::date wednesteenth() const;
    boost::gregorian::date thursteenth() const;
    boost::gregorian::date friteenth() const;
    boost::gregorian::date saturteenth() const;
    boost::gregorian::date sunteenth() const;

  private:
    const boost::gregorian::greg_month m_month;
    const unsigned int m_year;
};
} // namespace meetup

#endif // MEETUP_H
