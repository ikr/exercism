#ifndef ALLERGIES_H
#define ALLERGIES_H
#include <string>
#include <unordered_set>

namespace allergies {
struct allergy_test final {
    explicit allergy_test(const unsigned int code);
    bool is_allergic_to(const std::string &substance) const;
    std::unordered_set<std::string> get_allergies() const;

  private:
    unsigned int m_code;
};
} // namespace allergies

#endif // ALLERGIES_H
