class Squares(n: Int) {
    private val n: Int
    init { this.n = n }

    fun squareOfSum(): Int =
        (n * (n + 1) / 2).square()

    fun sumOfSquares(): Int =
        (1..n).sumBy(Int::square)

    fun difference(): Int =
        (1..n)
            .flatMap {x -> ((x + 1)..n).map {y -> Pair(x, y)}}
            .sumBy { 2 * it.first * it.second}
}

private fun Int.square(): Int =
    this * this
