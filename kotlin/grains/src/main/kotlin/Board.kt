import java.math.BigInteger

object Board {
    fun getGrainCountForSquare(x: Int): BigInteger {
        require(x in 1..64) { "Only integers between 1 and 64 (inclusive) are allowed" }
        return BigInteger.valueOf(2).pow(x - 1)
    }

    fun getTotalGrainCount(): BigInteger =
        BigInteger.valueOf(2).pow(64) - BigInteger.ONE
}
