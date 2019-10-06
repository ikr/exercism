#include "food_chain.h"
#include <cassert>
#include <numeric>
#include <sstream>
#include <vector>

namespace {
struct Object {
    std::string name;
    std::string addendum;
    std::string judgment;
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

std::string verse_closing_line(const Object &obj) {
    std::stringstream result;

    if (obj.addendum.length())
        result << "It " << obj.addendum << ".\n";
    else
        result << obj.judgment << "\n";

    return result.str();
}

std::string build_chain(const int obj_idx) {
    if (obj_idx == 1) return "";
    std::stringstream result;

    for (int i = obj_idx; i > 1; --i) {
        const auto a = chain_definition.at(i);
        const auto b = chain_definition.at(i - 1);

        result << "She swallowed the " << a.name << " to catch the " << b.name;
        if (b.addendum.length()) result << " that " << b.addendum;
        result << ".\n";
    }

    if (obj_idx) result << verse_closing_line(chain_definition.at(1));
    return result.str();
}
} // namespace

namespace food_chain {
std::string verse(const unsigned int verse_num) {
    assert(0 < verse_num && verse_num <= chain_definition.size());
    const int obj_idx = verse_num % chain_definition.size();
    const auto obj = chain_definition.at(obj_idx);

    std::stringstream result;
    result << "I know an old lady who swallowed a " << obj.name << ".\n"
           << verse_closing_line(obj) << build_chain(obj_idx);

    return result.str();
}

std::string verses(const unsigned int from_num, const unsigned int to_num) {
    assert(from_num <= to_num);

    std::vector<int> nums(to_num - from_num + 1);
    std::iota(nums.begin(), nums.end(), from_num);
    return std::accumulate(nums.cbegin(), nums.cend(), std::string{},
                           [](const std::string &acc, const int obj_idx) {
                               return acc + verse(obj_idx) + "\n";
                           });
}

std::string sing() { return verses(1, chain_definition.size()); }
} // namespace food_chain
