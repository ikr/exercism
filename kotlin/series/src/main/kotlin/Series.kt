object Series {
    fun slices(length: Int, s: String): List<List<Int>> =
        s.windowed(length, 1).map(::digits)
}

private fun digits(s: String): List<Int> =
    s.map { it.toString().toInt() }
