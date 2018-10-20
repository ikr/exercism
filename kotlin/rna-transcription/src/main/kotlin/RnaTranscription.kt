fun transcribeToRna(dna: String): String
    = dna.map(::rnaComplement).joinToString("")

private fun rnaComplement(dnaNucleo: Char): Char
    = when (dnaNucleo) {
        'C' -> 'G'
        'G' -> 'C'
        'T' -> 'A'
        'A' -> 'U'
        else -> '-'
    }
