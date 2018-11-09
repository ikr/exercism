data class Series(val s: String) {
    init {
        require(Regex("^[0-9]*$") matches s)
    }

    fun getLargestProduct(length: Int): Int {
        require(length <= s.length)

        val subSeqs = s.split("0").filter {it != ""}
        val subSolutions = subSeqs.map {largestProductOfNonZeroes(digits(it), length)}
        return subSolutions.max() ?: 1
    }
}

private fun largestProductOfNonZeroes(ds: List<Int>, length: Int): Int {
    var result = product(ds.take(length))
    var runningProd = result

    for (i in length..(ds.size - 1)) {
        runningProd = (runningProd / (ds[i - length])) * ds[i]

        if (runningProd > result) {
            result = runningProd
        }
    }

    return result
}

private fun digits(s: String) =
    s.map {it.toString().toInt()}

private fun product(xs: List<Int>): Int =
    xs.fold(1, {m, x -> m * x})
