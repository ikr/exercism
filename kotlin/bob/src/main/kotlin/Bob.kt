object Bob {
    fun hey(message: String): String =
        when {
            isExclaimation(message) -> "Whoa, chill out!"
            isQuestion(message) -> "Sure."
            isSilence(message) -> "Fine. Be that way!"
            else -> "Whatever."
        }
}

private fun isSilence(message: String) =
    message.all({!isLetter(it) && !isDigit(it)})

private fun isExclaimation(message: String) =
    message.all(::uppercaseOrNotLetter) && message.any(::isLetter)

private fun uppercaseOrNotLetter(c: Char) =
    (c in 'A'..'Z') || (c !in 'a'..'z')

private fun isLetter(c: Char) =
    c.toUpperCase() in 'A'..'Z'

private fun isDigit(c: Char) =
   c in '0'..'9'

private fun isQuestion(message: String) =
    !message.trim().isEmpty() && (message.trim().last() == '?')
