package Isogram

import java.util.HashSet

fun isIsogram(s: String): Boolean {
    val seen = HashSet<Char>()

    for (c in s.toLowerCase()) {
        if (!isLetter(c)) continue

        if (seen.contains(c)) {
            return false
        } else {
            seen.add(c)
        }
    }

    return true
}

private fun isLetter(c: Char): Boolean = (c >= 'a') && (c <= 'z')
