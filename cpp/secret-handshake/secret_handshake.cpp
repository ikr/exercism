#include "secret_handshake.h"
#include <algorithm>
#include <cassert>
#include <functional>
#include <map>

namespace {
using Transformer =
    std::function<std::vector<std::string>(std::vector<std::string>)>;

Transformer make_append(const std::string &what) {
    return [what](std::vector<std::string> commands) {
        commands.push_back(what);
        return commands;
    };
}

std::vector<std::string> reverse(std::vector<std::string> commands) {
    std::reverse(commands.begin(), commands.end());
    return commands;
}

static const std::map<unsigned int, Transformer> transformations_by_bit{
    {0b1, make_append("wink")},
    {0b10, make_append("double blink")},
    {0b100, make_append("close your eyes")},
    {1000, make_append("jump")},
    {0b10000, reverse}};
} // namespace

namespace secret_handshake {
std::vector<std::string> commands(const unsigned int code) {
    assert(code > 0);
    return {"wink"};
}
} // namespace secret_handshake
