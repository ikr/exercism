#if !defined(CIRCULAR_BUFFER_H)
#define CIRCULAR_BUFFER_H

#include <cassert>

namespace circular_buffer {

template <typename T> struct circular_buffer final {
    circular_buffer(const int size) { assert(size > 0); }
    T read() { throw std::domain_error("The buffer is empty"); }
};

} // namespace circular_buffer

#endif // CIRCULAR_BUFFER_H
