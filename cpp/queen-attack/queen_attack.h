#ifndef QUEEN_ATTACK_H
#define QUEEN_ATTACK_H
#include <utility>

namespace queen_attack {
using row_col = std::pair<int, int>;

struct chess_board {
    chess_board();
    const row_col &white() const;
    const row_col &black() const;

  private:
    row_col m_white;
    row_col m_black;
};
} // namespace queen_attack

#endif // QUEEN_ATTACK_H
