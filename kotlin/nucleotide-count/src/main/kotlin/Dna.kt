class Dna(s: String) {
    init { require(Regex("^[ACGT]*$") matches s) }

    val nucleotideCounts: Map<Char, Int> =
        s
            .groupingBy {it}
            .aggregateTo(
                mutableMapOf('A' to 0, 'C' to 0, 'G' to 0, 'T' to 0)
            ) {_, memo, _, _ -> (memo ?: 0) + 1}
}
