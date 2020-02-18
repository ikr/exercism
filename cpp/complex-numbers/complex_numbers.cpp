#include "complex_numbers.h"
#include <cmath>

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

double Complex::abs() const { return std::sqrt(m_re * m_re + m_im * m_im); }
Complex Complex::conj() const { return {m_re, -m_im}; }

Complex Complex::exp() const {
    return Complex{std::exp(m_re), 0.0} *
           Complex{std::cos(m_im), std::sin(m_im)};
}
} // namespace complex_numbers
