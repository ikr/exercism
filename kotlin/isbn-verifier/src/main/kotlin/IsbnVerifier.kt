class IsbnVerifier {
    fun isValid(s: String): Boolean {
        val digitsString = s.filter(::isValidDigit)
        if (!isValidStructure(digitsString)) return false

        val ds = digitsString.map(::digit)
        return ds.zip(10 downTo 1).map(::mul).sum() % 11 == 0
    }
}

private fun isValidStructure(digitsString: String): Boolean =
    Regex("^[0-9]{9}[0-9X]$") matches digitsString

private fun isValidDigit(c: Char) =
    c == 'X' || (c >= '0' && c <= '9')

private fun digit(c: Char): Int =
    if (c == 'X')
        10
    else
        c.toString().toInt()

private fun mul(pair: Pair<Int, Int>): Int =
    pair.first * pair.second
