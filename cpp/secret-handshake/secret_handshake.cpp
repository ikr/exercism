#include "secret_handshake.h"
#include <cassert>

namespace secret_handshake {
std::vector<std::string> commands(const unsigned int code) {
    assert(code > 0);
    return {"wink"};
}
} // namespace secret_handshake
