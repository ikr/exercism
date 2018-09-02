class Anagram(val source: String) {
    private val charCounts = countChars(source)

    fun match(candidates: List<String>): Set<String> {
        return HashSet(candidates.filter(::isAnagram))
    }

    private fun isAnagram(candidate: String): Boolean {
        return source.toLowerCase() != candidate.toLowerCase() &&
            charCounts == countChars(candidate)
    }
}

private fun countChars(source: String): Map<Char, Int> {
    val result = HashMap<Char, Int>()

    for (c: Char in source.toLowerCase()) {
        val currentCount = result.getOrDefault(c, 0)
        result.put(c, currentCount + 1)
    }

    return result
}
