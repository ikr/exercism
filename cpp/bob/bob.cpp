#include "bob.h"
#include <algorithm>
#include <locale>

namespace {
const std::locale &locale() {
    static std::locale l{};
    return l;
}

bool is_silence(std::string phrase) {
    return all_of(phrase.begin(), phrase.end(),
                  [](const char c) { return std::isspace(c, locale()); });
}

bool is_letter(const char c) { return std::isalpha(c, locale()); }

bool is_yelling(const std::string &phrase) {
    return std::all_of(phrase.cbegin(), phrase.cend(),
                       [](const char c) {
                           return std::isupper(c, locale()) || !is_letter(c);
                       }) &&
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

    return is_yelling(phrase)
               ? (is_question(phrase) ? "Calm down, I know what I'm doing!"
                                      : "Whoa, chill out!")
               : (is_question(phrase) ? "Sure." : "Whatever.");
}
} // namespace bob
