#include "matching_brackets.h"
#include <map>
#include <set>
#include <stack>

namespace {
const std::set<char> opening_brackets{'(', '[', '{'};

const std::map<char, char> opening_brackets_by_closing_bracket{
    {')', '('}, {']', '['}, {'}', '{'}};
} // namespace

namespace matching_brackets {
bool check(const std::string &expression) {
    std::stack<char> opened;

    for (const auto symbol : expression) {
        if (opening_brackets.count(symbol))
            opened.push(symbol);
        else if (opening_brackets_by_closing_bracket.count(symbol)) {
            if (opened.empty()) return false;

            const auto expected_opening =
                opening_brackets_by_closing_bracket.at(symbol);

            if (opened.top() != expected_opening) return false;
            opened.pop();
        }
    }

    return opened.empty();
}
} // namespace matching_brackets
