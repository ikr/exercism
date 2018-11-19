class MinesweeperBoard(lines: List<String>) {
    private val lines: List<String>

    init { this.lines = lines }

    fun withNumbers(): List<String> =
        (0 until lines.size).map(this::lineWithNumbers)

    private fun lineWithNumbers(row: Int): String =
        lines[row].mapIndexed { column, x ->
            if (x == '*')
                "*"
            else
                Coord(row, column)
                    .neighbors(lines.size, lines[row].length)
                    .count { square(it) == '*' }
                    .zeroToSpace()
        }.joinToString("")

    private fun square(coord: Coord): Char =
        lines[coord.row][coord.column]
}

private fun Int.zeroToSpace(): String =
    if (this == 0)
        " "
    else
        this.toString()

private data class Coord(val row: Int, val column: Int) {
    fun add(other: Coord): Coord =
        Coord(row + other.row, column + other.column)

    fun neighbors(rowsCount: Int, columnsCount: Int): List<Coord> =
        neighborDeltas
            .map { it.add(this) }
            .filter {
                it.row >= 0 &&
                it.row < rowsCount &&
                it.column >= 0 &&
                it.column < columnsCount
            }
}

private val neighborDeltas: List<Coord> =
    listOf(
        Coord(0, 1),
        Coord(-1, 1),
        Coord(-1, 0),
        Coord(-1, -1),
        Coord(0, -1),
        Coord(1, -1),
        Coord(1, 0),
        Coord(1, 1)
    )
