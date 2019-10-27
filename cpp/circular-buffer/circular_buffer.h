#if !defined(CIRCULAR_BUFFER_H)
#define CIRCULAR_BUFFER_H

#include "Optional.h"
#include <algorithm>
#include <cassert>
#include <optional>
#include <vector>

namespace circular_buffer {

template <typename T> struct circular_buffer final {
    circular_buffer(const int size) : m_elements(size) { assert(size > 0); }

    T read() {
        if (!bool(m_idx_oldest)) throw std::domain_error("The buffer is empty");

        const T result = *m_elements[*m_idx_oldest];
        m_elements[*m_idx_oldest] = opt::Optional<T>{};

        int i = *m_idx_oldest;
        m_idx_oldest = opt::Optional<int>{};

        if (std::all_of(m_elements.cbegin(), m_elements.cend(),
                        [](auto el) { return !bool(el); }))
            return result;

        while (!bool(m_elements[i])) i = (i + 1) % m_elements.size();
        m_idx_oldest = opt::Optional<int>{i};

        return result;
    }

    void write(const T x) {
        if (std::all_of(m_elements.cbegin(), m_elements.cend(),
                        [](auto el) { return bool(el); }))
            throw std::domain_error("The buffer is full.");

        int i = 0;

        if (bool(m_idx_oldest)) {
            i = *m_idx_oldest;
            while (bool(m_elements[i])) i = (i + 1) % m_elements.size();
        } else
            m_idx_oldest = opt::Optional<int>{0};

        m_elements[i] = opt::Optional<T>{x};
    }

    void clear() {
        std::fill(m_elements.begin(), m_elements.end(), opt::Optional<T>{});
        m_idx_oldest = opt::Optional<int>{};
    }

  private:
    std::vector<opt::Optional<T>> m_elements;
    opt::Optional<int> m_idx_oldest;
};

} // namespace circular_buffer

#endif // CIRCULAR_BUFFER_H
