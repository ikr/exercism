#if !defined(FOOD_CHAIN_H)
#define FOOD_CHAIN_H

#include <string>

namespace food_chain {
std::string verse(const unsigned int verse_num);
std::string verses(const unsigned int from_num, const unsigned int to_num);
std::string sing();
} // namespace food_chain

#endif // FOOD_CHAIN_H
