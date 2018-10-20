class DiamondPrinter {
    fun printToList(x: Char): List<String> =
        (('A'..x) + (x.dec() downTo 'A')).map({line(x, it)})
}

private fun line(last: Char, x: Char): String {
    val m = " ".repeat(margin(last, x))
    val d = " ".repeat(diameter(x))

    return if (d == "")
        "$m$x$m"
    else
        "$m$x$d$x$m"
}

private fun diameter(x: Char) =
    if (x == 'A')
        0
    else
        2 * (x.toInt() - 'A'.toInt()) - 1

private fun margin(last: Char, x: Char) =
    last.toInt() - x.toInt()
