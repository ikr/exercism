#include "queen_attack.h"

namespace queen_attack {
chess_board::chess_board() : m_white{0, 3}, m_black{7, 3} {}
const row_col &chess_board::white() const { return m_white; }
const row_col &chess_board::black() const { return m_black; }
} // namespace queen_attack
