import java.math.BigInteger

object Board {
    fun getGrainCountForSquare(x: Int): BigInteger {
        require(x > 0 && x < 65) { "Only integers between 1 and 64 (inclusive) are allowed" }
        return BigInteger.valueOf(2).pow(x - 1)
    }

    fun getTotalGrainCount(): BigInteger =
        (1..64)
            .map(Board::getGrainCountForSquare)
            .reduce(BigInteger::add)
}
