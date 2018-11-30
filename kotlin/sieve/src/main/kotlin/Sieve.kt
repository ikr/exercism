import kotlin.math.min

object Sieve {
    fun primesUpTo(limit: Int): List<Int> {
        val isIndexPrime = Array(limit + 1) { if (it < 2) false else true }
        var cursor = 2

        while (cursor <= limit) {
            for (i in (cursor * 2)..limit step cursor) {
                isIndexPrime[i] = false
            }

            do {
                cursor++
            } while (cursor <= limit && !isIndexPrime[cursor])
        }

        return collectPrimes(isIndexPrime)
    }
}

private fun collectPrimes(isIndexPrime: Array<Boolean>): List<Int> {
    val result = mutableListOf<Int>()

    for ((i, v) in isIndexPrime.withIndex()) {
        if (v) result += i
    }

    return result
}
