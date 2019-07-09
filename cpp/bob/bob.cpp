#include "bob.h"
#include <algorithm>
#include <locale>

namespace {
const std::locale &locale() {
    static std::locale l{};
    return l;
}

bool is_letter(const char c) { return std::isalpha(c, locale()); }
bool is_space(const char c) { return std::isspace(c, locale()); }
bool is_upper_or_nor_leter(const char c) {
    return std::isupper(c, locale()) || !is_letter(c);
}

bool is_silence(std::string phrase) {
    return all_of(phrase.begin(), phrase.end(), is_space);
}

bool is_yelling(const std::string &phrase) {
    return std::all_of(phrase.cbegin(), phrase.cend(), is_upper_or_nor_leter) &&
           std::any_of(phrase.cbegin(), phrase.cend(), is_letter);
}

bool is_question(const std::string &phrase) {
    const auto last_not_space = phrase.find_last_not_of(' ');
    return last_not_space != std::string::npos && phrase[last_not_space] == '?';
}
} // namespace

namespace bob {
std::string hey(const std::string &phrase) {
    if (is_silence(phrase)) return "Fine. Be that way!";

    if (is_yelling(phrase)) {
        return (is_question(phrase) ? "Calm down, I know what I'm doing!"
                                    : "Whoa, chill out!");
    }

    return is_question(phrase) ? "Sure." : "Whatever.";
}
} // namespace bob
