class Allergies(score: Int) {
    private val score: Int
    init { this.score = score }

    fun isAllergicTo(a: Allergen): Boolean =
        score and a.score > 0

    fun getList(): List<Allergen> =
        Allergen.values().filter { it.score and score > 0 }
}
