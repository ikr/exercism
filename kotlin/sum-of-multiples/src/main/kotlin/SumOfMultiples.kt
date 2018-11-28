import kotlin.sequences.generateSequence

object SumOfMultiples {
    fun sum(xs: Set<Int>, limit: Int): Int =
        xs.flatMap { multiples(it, limit).toList() }.toSet().sum()
}

fun multiples(x: Int, limit: Int): Sequence<Int> =
    generateSequence({ if (x < limit) x else null })
        { if (it + x < limit) it + x else null }
