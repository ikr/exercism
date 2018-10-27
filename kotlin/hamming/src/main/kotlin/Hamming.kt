import kotlin.math.*

object Hamming {
    fun compute(s1: String, s2: String): Int =
        if (s1.length == s2.length)
            s1.zip(s2)
                .map({it.first.compareTo(it.second).absoluteValue})
                .sum()
        else
            throw IllegalArgumentException(
                "left and right strands must be of equal length."
            )
}
