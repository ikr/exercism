#if !defined(COMPLEX_NUMBERS_H)
#define COMPLEX_NUMBERS_H

namespace complex_numbers {
struct Complex final {
    Complex(const double re, const double im);
    double real() const;
    double imag() const;

  private:
    double m_re;
    double m_im;
};
} // namespace complex_numbers

#endif // COMPLEX_NUMBERS_H
