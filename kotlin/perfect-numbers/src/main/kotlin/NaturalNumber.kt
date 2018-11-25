enum class Classification {
    DEFICIENT, PERFECT, ABUNDANT
}

fun classify(x: Int): Classification {
    require(x > 0)

    val s = factors(x).sum()

    return when (s) {
        0 -> Classification.DEFICIENT

        in 1..x -> if (s == x)
            Classification.PERFECT
        else
            Classification.DEFICIENT

        else -> Classification.ABUNDANT
    }
}

private fun factors(x: Int): List<Int> =
    (1 until x).filter { x % it == 0 }
