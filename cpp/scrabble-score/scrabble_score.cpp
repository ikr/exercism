#include "scrabble_score.h"
#include <locale>
#include <numeric>
#include <unordered_map>

namespace {
const std::unordered_map<char, int> scores_by_uppercased_letter = {
    {'A', 1},  {'E', 1}, {'I', 1}, {'O', 1}, {'U', 1},
    {'L', 1},  {'N', 1}, {'R', 1}, {'S', 1}, {'T', 1},

    {'D', 2},  {'G', 2},

    {'B', 3},  {'C', 3}, {'M', 3}, {'P', 3},

    {'F', 4},  {'H', 4}, {'V', 4}, {'W', 4}, {'Y', 4},

    {'K', 5},

    {'J', 8},  {'X', 8},

    {'Q', 10}, {'Z', 10}};

int one_letter_score(const char letter) {
    const char uppercased = std::toupper(letter, std::locale::classic());
    return scores_by_uppercased_letter.count(uppercased)
               ? scores_by_uppercased_letter.at(uppercased)
               : 0;
}
} // namespace

namespace scrabble_score {
int score(const std::string &word) {
    return std::accumulate(word.cbegin(), word.cend(), 0,
                           [](const int sum, const char letter) {
                               return sum + one_letter_score(letter);
                           });
}
} // namespace scrabble_score
