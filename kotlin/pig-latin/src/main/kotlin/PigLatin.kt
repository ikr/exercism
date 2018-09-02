package PigLatin

fun translate(s: String): String {
    return s.split(' ').map(::translateWord).joinToString(" ")
}

fun translateWord(s: String): String {
    if (startsWithVowel(s)) {
        return s + "ay"
    }

    val ccl = consonantClusterLength(s)
    return s.substring(ccl) + s.substring(0, ccl) + "ay"
}

fun startsWithVowel(s: String): Boolean =
    s.substring(0, 2) == "xr" ||
    s.substring(0, 2) == "yt" ||
    (s.length > 0 && s[0] in listOf('a', 'e', 'i', 'o', 'u'))

fun consonantClusterLength(s: String): Int {
    var i = 0

    while (i < s.length && (
        s[i] !in listOf('a', 'e', 'i', 'o', 'u', 'y') ||
        (i > 0 && s[i - 1] == 'q' && s[i] == 'u') ||
        (i == 0 && s[i] == 'y')
    )) {
        i++
    }

    return i
}
