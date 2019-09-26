#include "food_chain.h"
#include <cassert>
#include <set>
#include <vector>
#include <sstream>

namespace {
enum class OptionalProperty { ADDENDUM, JUDGEMENT };

struct Object {
    std::string name;
    std::set<OptionalProperty> present_optionals;
    std::string addendum;
    std::string judgement;
};

const std::vector<Object> chain_definition{
    {"fly",
     {OptionalProperty::JUDGEMENT},
     "",
     "I don't know why she swallowed the fly. Perhaps she'll die."}};
} // namespace

namespace food_chain {
std::string verse(const unsigned int verse_num) {
    assert(0U < verse_num && verse_num <= chain_definition.size());

    const auto obj = chain_definition.at(verse_num - 1);

    std::stringstream result;
    result << "I know an old lady who swallowed a " << obj.name << ".\n";

    if (obj.present_optionals.count(OptionalProperty::ADDENDUM)) {
        result << "It " << obj.addendum << ".\n";
    }

    if (obj.present_optionals.count(OptionalProperty::JUDGEMENT)) {
        result << obj.judgement << '\n';
    }

    return result.str();
}
} // namespace food_chain
