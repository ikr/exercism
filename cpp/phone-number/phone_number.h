#if !defined(PHONE_NUMBER_H)
#define PHONE_NUMBER_H

#include <string>

namespace phone_number {
struct phone_number final {
    phone_number(const std::string &source);
    std::string number() const;

  private:
    std::string m_digits;
};
} // namespace phone_number

#endif // PHONE_NUMBER_H