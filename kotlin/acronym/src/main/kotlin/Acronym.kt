object Acronym {
    fun generate(phrase: String): String =
        phrase
            .split(" ", "-")
            .filter(String::isNotEmpty)
            .map {it.first().toUpperCase()}
            .joinToString("")
}
