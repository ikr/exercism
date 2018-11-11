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

private fun firstNotExceeding(x: Int): Primitive =
    primitives.first {it.value <= x}

private val primitives = arrayOf(
    Primitive(1000, "M"),
    Primitive(900, "CM"),
    Primitive(800, "DCCC"),
    Primitive(700, "DCC"),
    Primitive(600, "DC"),
    Primitive(500, "D"),
    Primitive(400, "CD"),
    Primitive(300, "CCC"),
    Primitive(200, "CC"),
    Primitive(100, "C"),
    Primitive(90, "XC"),
    Primitive(80, "LXXX"),
    Primitive(70, "LXX"),
    Primitive(60, "LX"),
    Primitive(50, "L"),
    Primitive(40, "XL"),
    Primitive(30, "XXX"),
    Primitive(20, "XX"),
    Primitive(10, "X"),
    Primitive(9, "IX"),
    Primitive(8, "VIII"),
    Primitive(7, "VII"),
    Primitive(6, "VI"),
    Primitive(5, "V"),
    Primitive(4, "IV"),
    Primitive(3, "III"),
    Primitive(3, "II"),
    Primitive(1, "I")
)

private data class Primitive(val value: Int, val literal: String)
