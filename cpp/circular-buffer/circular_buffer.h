#if !defined(CIRCULAR_BUFFER_H)
#define CIRCULAR_BUFFER_H

#include "Optional.h"
#include <algorithm>
#include <cassert>
#include <vector>

namespace circular_buffer {

template <typename T> struct circular_buffer final {
    circular_buffer(const int size) : m_elements(size) { assert(size > 0); }

    T read() {
        if (!m_idx_oldest) throw std::domain_error("The buffer is empty");

        const T result = *m_elements[*m_idx_oldest];
        m_elements[*m_idx_oldest] = opt::nullopt;

        int i = *m_idx_oldest;
        m_idx_oldest = opt::nullopt;

        if (std::all_of(m_elements.cbegin(), m_elements.cend(),
                        [](auto el) { return !el; }))
            return result;

        while (!m_elements[i]) i = (i + 1) % m_elements.size();
        m_idx_oldest = opt::Optional<int>{i};

        return result;
    }

    void write(const T &x) {
        if (is_full()) throw std::domain_error("The buffer is full.");
        positive_capacity_write(x);
    }

    void overwrite(const T &x) {
        if (is_full()) {
            m_elements[*m_idx_oldest] = opt::Optional<T>{x};
            m_idx_oldest =
                opt::Optional<int>{(*m_idx_oldest + 1) % m_elements.size()};
        } else
            positive_capacity_write(x);
    }

    void clear() {
        std::fill(m_elements.begin(), m_elements.end(), opt::nullopt);
        m_idx_oldest = opt::nullopt;
    }

  private:
    bool is_full() const {
        return std::all_of(m_elements.cbegin(), m_elements.cend(),
                           [](auto el) { return el; });
    }

    void positive_capacity_write(const T &x) {
        int i = 0;

        if (m_idx_oldest) {
            i = *m_idx_oldest;
            while (m_elements[i]) i = (i + 1) % m_elements.size();
        } else
            m_idx_oldest = opt::Optional<int>{0};

        m_elements[i] = opt::Optional<T>{x};
    }

    std::vector<opt::Optional<T>> m_elements;
    opt::Optional<int> m_idx_oldest;
};

} // namespace circular_buffer

#endif // CIRCULAR_BUFFER_H
