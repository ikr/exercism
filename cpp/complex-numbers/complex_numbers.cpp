#include "complex_numbers.h"

namespace complex_numbers {
Complex::Complex(const double re, const double im) : m_re{re}, m_im{im} {}
double Complex::real() const { return m_re; }
double Complex::imag() const { return m_im; }
} // namespace complex_numbers
