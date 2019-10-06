#include "beer_song.h"
#include <locale>
#include <sstream>

namespace {
std::string pronoun(const int count) { return count == 1 ? "it" : "one"; }

std::string capitalize(std::string s) {
    if (!s.length()) return s;
    s[0] = std::toupper(s[0], std::locale::classic());
    return s;
}

std::string bottles_of_beer(const int count) {
    const auto quantity{count ? std::to_string(count) : std::string{"no more"}};
    const std::string bottles{count == 1 ? "bottle" : "bottles"};

    std::stringstream result;
    result << quantity << ' ' << bottles << " of beer";
    return result.str();
}

std::string line1(const int count) {
    std::stringstream result;
    result << capitalize(bottles_of_beer(count)) << " on the wall, "
           << bottles_of_beer(count) << '.';
    return result.str();
}

std::string line2(const int count) {
    if (count) {
        std::stringstream result;

        result << "Take " << pronoun(count) << " down and pass it around, "
               << bottles_of_beer(count - 1) << " on the wall.";
        return result.str();
    }

    return "Go to the store and buy some more, 99 bottles of beer on the wall.";
}
} // namespace

namespace beer_song {
std::string verse(const int count) {
    std::stringstream result;
    result << line1(count) << '\n' << line2(count) << '\n';
    return result.str();
}

std::string sing(const int from_count, const int to_count) {
    std::stringstream result;
    for (int i = from_count; i >= to_count; --i) {
        result << verse(i);
        if (i != to_count) result << '\n';
    }
    return result.str();
}
} // namespace beer_song
