import kotlin.math.sqrt

enum class Classification {
    DEFICIENT, PERFECT, ABUNDANT
}

fun classify(x: Int): Classification {
    require(x > 0)
    val s = factors(x).sum()

    return when (s) {
        1 -> Classification.DEFICIENT

        in 2..x -> if (s == x)
            Classification.PERFECT
        else
            Classification.DEFICIENT

        else -> Classification.ABUNDANT
    }
}

private fun factors(x: Int): List<Int> {
    val result = mutableListOf(1)

    (2..x.sqrt()).forEach {
        if (x % it == 0) {
            result.add(it)
            if (x / it != it) result.add(x / it)
        }
    }

    return result
}

private fun Int.sqrt() =
    sqrt(this.toDouble()).toInt()
