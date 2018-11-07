object Luhn {
    fun isValid(xs: String): Boolean {
        val noSpaces = xs.filter {it != ' ' }

        if (noSpaces.length < 2 || !(Regex("^[0-9]+$") matches noSpaces)) return false

        val digits = noSpaces.map {it.toString().toInt()}.reversed()

        val capDoubled = digits.mapIndexed {i, d ->
            if (i % 2 == 1)
                capDouble(d)
            else
                d
        }

        return capDoubled.sum() % 10 == 0
    }
}

private fun capDouble(x: Int) =
    if (x * 2 > 9) x * 2 - 9
    else x * 2
