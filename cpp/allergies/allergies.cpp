#include "allergies.h"
#include <unordered_map>

namespace {
const std::unordered_map<std::string, unsigned int> bitcodes_by_substance{
    {"eggs", 1},      {"peanuts", 2},    {"shellfish", 4}, {"strawberries", 8},
    {"tomatoes", 16}, {"chocolate", 32}, {"pollen", 64},   {"cats", 128}};
} // namespace

namespace allergies {
allergy_test::allergy_test(const unsigned int code) : m_code(code) {}

bool allergy_test::is_allergic_to(const std::string &substance) const {
    return m_code & bitcodes_by_substance.at(substance);
}

std::unordered_set<std::string> allergy_test::get_allergies() const {
    std::unordered_set<std::string> answer;

    for (auto substance_and_code : bitcodes_by_substance)
        if (substance_and_code.second & m_code)
            answer.insert(substance_and_code.first);

    return answer;
}
} // namespace allergies
