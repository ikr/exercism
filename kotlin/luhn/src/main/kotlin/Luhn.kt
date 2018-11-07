object Luhn {
    fun isValid(xs: String): Boolean {
        val noSpaces = xs.filter {it != ' ' }

        if (noSpaces.length < 2 || !(Regex("^[0-9]+$") matches noSpaces)) return false

        val allDoubledCapped = noSpaces
            .reversed()
            .map {it.toString().toInt()}
            .mapIndexed {i, d ->
                if (i % 2 == 1)
                    doubleCapped(d)
                else
                    d
            }

       return allDoubledCapped.sum() % 10 == 0
    }
}

private fun doubleCapped(x: Int): Int {
    val x_2 = x * 2

    return if (x_2 > 9) x_2 - 9
    else x_2
}
