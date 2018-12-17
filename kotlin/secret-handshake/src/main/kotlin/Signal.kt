object HandshakeCalculator {
    fun calculateHandshake(x: Int): List<Signal> =
        Signal.values()
            .filter({ it.value and x != 0 })
            .let({ if ((x and 0b10000) != 0) it.reversed() else it })
}

enum class Signal(val value: Int) {
    WINK(0b1),
    DOUBLE_BLINK(0b10),
    CLOSE_YOUR_EYES(0b100),
    JUMP(0b1000)
}
