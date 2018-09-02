package Pangram

import java.util.HashSet

const val ALPHABET_SIZE = 26

fun isPangram(s: String): Boolean {
    val seen = HashSet<Char>()

    for (c: Char in s.toLowerCase()) {
        if (c >= 'a' && c <= 'z') seen.add(c)
    }

    return seen.size == ALPHABET_SIZE
}
