#include "scrabble_score.h"
#include <algorithm>
#include <locale>
#include <map>
#include <numeric>
#include <vector>

namespace {
const std::map<char, unsigned int> scores_by_uppercased_letter = {
    {'A', 1},  {'E', 1}, {'I', 1}, {'O', 1}, {'U', 1},
    {'L', 1},  {'N', 1}, {'R', 1}, {'S', 1}, {'T', 1},

    {'D', 2},  {'G', 2},

    {'B', 3},  {'C', 3}, {'M', 3}, {'P', 3},

    {'F', 4},  {'H', 4}, {'V', 4}, {'W', 4}, {'Y', 4},

    {'K', 5},

    {'J', 8},  {'X', 8},

    {'Q', 10}, {'Z', 10}};

unsigned int letter_score(const char letter) {
    const char uppercased = std::toupper(letter, std::locale::classic());
    return scores_by_uppercased_letter.count(uppercased)
               ? scores_by_uppercased_letter.at(uppercased)
               : 0;
}
} // namespace

namespace scrabble_score {
unsigned int score(const std::string &word) {
    std::vector<unsigned int> letter_scores(word.size());
    std::transform(word.cbegin(), word.cend(), letter_scores.begin(),
                   letter_score);
    return std::accumulate(letter_scores.cbegin(), letter_scores.cend(), 0);
}

} // namespace scrabble_score
