object RomanNumeral {
    fun value(x: Int): String {
        val result = StringBuilder()
        var remainder = x

        while (remainder > 0) {
            val next = firstNotExceeding(remainder)
            result.append(next.literal)
            remainder -= next.value
        }

        return result.toString()
    }
}

fun firstNotExceeding(x: Int): Term {
    for (i in 0 until atoms.size) {
        if (atoms[i].value <= x) return atoms[i]

        if (i % 2 == 0) {
            if ((atoms[i] - atoms[i + 2]).value <= x)
                return atoms[i] - atoms[i + 2]
        } else {
            val candidates = listOf(
                atoms[i] + atoms[i + 1] + atoms[i + 1] + atoms[i + 1],
                atoms[i] + atoms[i + 1] + atoms[i + 1],
                atoms[i] + atoms[i + 1],
                atoms[i] - atoms[i + 1]
            )

            val result = candidates.find {it.value <= x}
            if (result != null) return result
        }
    }

    throw IllegalStateException()
}

private val atoms = listOf(
    Term(1000, "M"),
    Term(500, "D"),
    Term(100, "C"),
    Term(50, "L"),
    Term(10, "X"),
    Term(5, "V"),
    Term(1, "I")
)

data class Term(val value: Int, val literal: String) {
    operator fun plus(other: Term): Term {
        return Term(value + other.value, literal + other.literal)
    }

    operator fun minus(other: Term): Term {
        return Term(value - other.value, other.literal + literal)
    }
}
