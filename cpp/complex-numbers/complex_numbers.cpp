#include "complex_numbers.h"

namespace complex_numbers {
Complex::Complex(const double re, const double im) : m_re{re}, m_im{im} {}
double Complex::real() const { return m_re; }
double Complex::imag() const { return m_im; }

Complex Complex::operator*(const Complex &rhs) const {
    const auto a = m_re, b = m_im, c = rhs.m_re, d = rhs.m_im;
    return {a * c - b * d, b * c + a * d};
}

Complex Complex::operator+(const Complex &rhs) const {
    return {m_re + rhs.m_re, m_im + rhs.m_im};
}

Complex Complex::operator-(const Complex &rhs) const {
    return {m_re - rhs.m_re, m_im - rhs.m_im};
}

Complex Complex::operator/(const Complex &rhs) const {
    const auto a = m_re, b = m_im, c = rhs.m_re, d = rhs.m_im;
    const auto denom = c * c + d * d;
    return {(a * c + b * d) / denom, (b * c - a * d) / denom};
}

bool Complex::abs() const { return 0; }
} // namespace complex_numbers
