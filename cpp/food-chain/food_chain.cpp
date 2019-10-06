#include "food_chain.h"
#include <cassert>
#include <set>
#include <sstream>
#include <vector>

namespace {
struct Object {
    std::string name;
    std::string addendum;
    std::string judgement;
};

const std::vector<Object> chain_definition{
    {"fly", "", ""},
    {"spider", "wriggled and jiggled and tickled inside her", ""}};
} // namespace

namespace food_chain {
std::string verse(const int last_obj_num) {
    assert(0 < last_obj_num &&
           last_obj_num <= static_cast<int>(chain_definition.size()));

    std::stringstream result;
    const auto obj = chain_definition.at(last_obj_num - 1);
    result << "I know an old lady who swallowed a " << obj.name << ".\n";

    if (obj.addendum.length())
        result << "It " << obj.addendum << ".\n";
    else if (obj.judgement.length())
        result << obj.judgement << "\n";

    for (int i = last_obj_num; i > 1; --i) {
        const auto a = chain_definition.at(i - 1);
        const auto b = chain_definition.at(i - 2);
        result << "She swallowed the " << obj.name << " to catch the " << b.name
               << ".\n";
    }

    result << "I don't know why she swallowed the fly. Perhaps she'll die.\n";

    return result.str();
}
} // namespace food_chain
