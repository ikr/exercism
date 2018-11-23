class Squares(n: Int) {
    private val n: Int
    init { this.n = n }

    fun squareOfSum(): Int =
        (n * (n + 1) / 2).square()

    fun sumOfSquares(): Int =
        (1..n).sumBy(Int::square)

    fun difference(): Int =
        squareOfSum() - sumOfSquares()
}

private fun Int.square(): Int =
    this * this
