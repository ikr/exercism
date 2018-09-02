package Raindrops

fun convert(x: Int): String {
    var result = ""

    if (x % 3 == 0) {
        result += "Pling"
    }

    if (x % 5 == 0) {
        result += "Plang"
    }

    if (x % 7 == 0) {
        result += "Plong"
    }

    return if (result == "") "$x" else result
}
