#ifndef GRADE_SCHOOL_H
#define GRADE_SCHOOL_H

#include <map>
#include <string>
#include <vector>

namespace grade_school {
using Names = std::vector<std::string>;
using Roster = std::map<int, Names>;

struct school final {
    const Roster &roster() const;
    Names grade(const int x) const;
    void add(const std::string &name, const int grade);

  private:
    Roster m_roster;
};
} // namespace grade_school

#endif // GRADE_SCHOOL_H
