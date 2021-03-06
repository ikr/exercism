object BeerSong {
    fun verses(first: Int, last: Int): String =
        (first downTo last).map(::verse).joinToString("\n")
}

private fun verse(count: Int): String =
    """
    |${line1(count)}
    |${line2(count)}
    |
    """.trimMargin()

private fun line1(count: Int): String =
    "${bottlesOfBeer(count).capitalize()} on the wall, ${bottlesOfBeer(count)}."

private fun line2(count: Int): String =
    if (count == 0)
        "Go to the store and buy some more, 99 bottles of beer on the wall."
    else
        "Take ${pronoun(count)} down and pass it around, ${bottlesOfBeer(count - 1)} on the wall."

private fun bottlesOfBeer(count: Int): String {
    val quantity = if (count == 0) "no more" else "$count"
    val bottles = if (count == 1) "bottle" else "bottles"
    return "$quantity $bottles of beer"
}

private fun pronoun(count: Int): String =
    if (count == 1) "it" else "one"
