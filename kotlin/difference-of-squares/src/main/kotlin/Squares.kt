class Squares(n: Int) {
    private val n: Int
    init { this.n = n }

    fun squareOfSum(): Int =
        (n * (n + 1) / 2).square()

    fun sumOfSquares(): Int =
        n * (n + 1) * (2 * n + 1) / 6

    fun difference(): Int =
        squareOfSum() - sumOfSquares()
}

private fun Int.square(): Int =
    this * this
