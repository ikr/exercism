#include "complex_numbers.h"

namespace complex_numbers {
Complex::Complex(const double re, const double im) : m_re{re}, m_im{im} {}
double Complex::real() const { return m_re; }
double Complex::imag() const { return m_im; }

Complex Complex::operator*(const Complex &rhs) const {
    return {m_re * rhs.m_re - m_im * rhs.m_im,
            m_im * rhs.m_re + m_re * rhs.m_im};
}

Complex Complex::operator+(const Complex &rhs) const {
    return {m_re + rhs.m_re, m_im + rhs.m_im};
}

Complex Complex::operator-(const Complex &rhs) const {
    return {m_re - rhs.m_re, m_im - rhs.m_im};
}
} // namespace complex_numbers
