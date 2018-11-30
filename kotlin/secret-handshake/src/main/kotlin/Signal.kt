object HandshakeCalculator {
    fun calculateHandshake(x: Int): List<Signal> {
        val binWithPrefix = x.toString(2).padStart(5, '0')
        val doReverse = binWithPrefix[0] == '1'
        val bin = binWithPrefix.substring(1)

        val result = bin
            .toList()
            .zip(Signal.values().reversed())
            .fold(
                mutableListOf<Signal>(),
                {agg, p ->
                    val (digit, signal) = p
                    if (digit == '1') agg.add(0, signal)
                    agg
                }
            )

        return if (doReverse)
            result.reversed()
        else
            result
    }
}

enum class Signal { WINK, DOUBLE_BLINK, CLOSE_YOUR_EYES, JUMP }
