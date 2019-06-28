#include "grade_school.h"
#include <algorithm>

namespace grade_school {
const Roster &school::roster() const { return m_roster; }

Names school::grade(const int x) const {
    return m_roster.count(x) ? m_roster.at(x) : Names{};
}

void school::add(const std::string &name, const int grade) {
    const auto ins_point = std::upper_bound(m_roster[grade].cbegin(),
                                            m_roster[grade].cend(), name);

    m_roster[grade].insert(ins_point, name);
}
} // namespace grade_school
