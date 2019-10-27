#ifndef OPTIONAL_H
#define OPTIONAL_H

#include <cassert>

namespace opt {

template <typename T> struct Optional final {
    Optional() : m_present{false}, m_value{} {}
    explicit Optional(const T &value) : m_present{true}, m_value{value} {}
    explicit operator bool() const { return m_present; }

    T operator*() const {
        assert(m_present);
        return m_value;
    }

  private:
    bool m_present;
    T m_value;
};

} // namespace opt

#endif // OPTIONAL_H
