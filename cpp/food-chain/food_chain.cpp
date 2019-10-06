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
    {"horse", "", "She's dead, of course!"},
    {"fly", "", "I don't know why she swallowed the fly. Perhaps she'll die."},
    {"spider", "wriggled and jiggled and tickled inside her", ""},
    {"bird", "", "How absurd to swallow a bird!"},
    {"cat", "", "Imagine that, to swallow a cat!"},
    {"dog", "", "What a hog, to swallow a dog!"},
    {"goat", "", "Just opened her throat and swallowed a goat!"},
    {"cow", "", "I don't know how she swallowed a cow!"}};
} // namespace

namespace food_chain {
std::string verse(const int last_obj_num) {
    assert(0 < last_obj_num &&
           last_obj_num <= static_cast<int>(chain_definition.size()));

    const int obj_idx = last_obj_num % chain_definition.size();

    std::stringstream result;
    const auto obj = chain_definition.at(obj_idx);
    result << "I know an old lady who swallowed a " << obj.name << ".\n";

    if (obj.addendum.length())
        result << "It " << obj.addendum << ".\n";
    else if (obj.judgement.length() && obj_idx != 1)
        result << obj.judgement << "\n";

    for (int i = obj_idx; i > 1; --i) {
        const auto a = chain_definition.at(i);
        const auto b = chain_definition.at(i - 1);

        result << "She swallowed the " << a.name << " to catch the " << b.name;
        if (b.addendum.length()) result << " that " << b.addendum;
        result << ".\n";
    }

    if (obj_idx) result << chain_definition[1].judgement << "\n";
    return result.str();
}
} // namespace food_chain
