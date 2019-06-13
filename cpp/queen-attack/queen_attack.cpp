#include "queen_attack.h"
#include <cstdlib>
#include <stdexcept>

namespace {
constexpr int board_size = 8;
using row_col = queen_attack::row_col;

std::string print_row(const int row_index, const row_col white,
                      const row_col black) {
    std::string result(board_size, '_');

    if (row_index == white.first) result[white.second] = 'W';
    if (row_index == black.first) result[black.second] = 'B';

    return result;
}

std::string format_row(const std::string &row) {
    std::string result{row};

    for (int i = 1; i != board_size * 2 - 1; i += 2) {
        result.insert(i, 1, ' ');
    }

    return result;
}
} // namespace

namespace queen_attack {
chess_board::chess_board() : m_white{0, 3}, m_black{7, 3} {}

chess_board::chess_board(const row_col white, const row_col black)
    : m_white(white), m_black(black) {
    if (m_white == m_black)
        throw std::domain_error("Queens must not occupy the same position");
}

row_col chess_board::white() const { return m_white; }
row_col chess_board::black() const { return m_black; }

chess_board::operator std::string() const {
    std::string result;

    for (int i = 0; i != board_size; ++i) {
        result += format_row(print_row(i, m_white, m_black)) + "\n";
    }

    return result;
}

bool chess_board::can_attack() const {
    const int row_diff = std::abs(m_white.first - m_black.first);
    const int col_diff = std::abs(m_white.second - m_black.second);

    return row_diff == col_diff || !row_diff || !col_diff;
}
} // namespace queen_attack
