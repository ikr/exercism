#include "food_chain.h"
#include <cassert>

namespace food_chain {
std::string verse(const unsigned int verse_num) {
    assert(verse_num > 0U);

    return "I know an old lady who swallowed a fly.\n"
           "I don't know why she swallowed the fly. Perhaps she'll die.\n";
}
} // namespace food_chain
