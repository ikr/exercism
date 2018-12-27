class Triangle(a: Double, b: Double, c: Double) {
    private val lengthsCount = setOf(a, b, c).size

    init {
        require(listOf(a, b, c).all({ it > 0 }))
        require(a + b > c && a + c > b && b + c > a)
    }

    constructor(a: Int, b: Int, c: Int): this(a.toDouble(), b.toDouble(), c.toDouble())

    val isEquilateral: Boolean
        get() = lengthsCount == 1

    val isIsosceles: Boolean
        get() = lengthsCount < 3

    val isScalene: Boolean
        get() = lengthsCount == 3
}
