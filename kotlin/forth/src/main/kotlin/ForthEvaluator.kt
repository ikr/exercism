import java.util.Stack
import kotlin.text.toInt
import kotlin.text.toIntOrNull

class ForthEvaluator {
    private val stack = Stack<Int>()
    private val macros = mutableMapOf<String, List<String>>()

    fun evaluateProgram(p: List<String>): List<Int> {
        p
            .map(String::toLowerCase)
            .map({ it.split(" ") })
            .forEach {
                if (it.first() == ":")
                    evalMacro(it)
                else
                    evalLine(translateLine(it))
            }

        return stack.toList()
    }

    private fun translateLine(tokens: List<String>): List<String> {
        if (tokens.isEmpty()) return tokens

        val replacement = macros[tokens.first()]

        val head = if (replacement != null)
            translateLine(replacement)
        else
            listOf(tokens.first())

        return head + translateLine(tokens.drop(1))
    }

    private fun evalLine(tokens: List<String>) {
        tokens.forEach({ token ->
            when {
                token in opsByToken -> opsByToken[token]?.invoke(stack)
                token.toIntOrNull() != null -> stack.push(token.toInt())
                else -> throw IllegalArgumentException(
                    "No definition available for operator \"$token\""
                )
            }
        })
    }

    private fun evalMacro(tokens: List<String>) {
        val name = tokens[1]

        require(name.toIntOrNull() == null) {
            "Cannot redefine numbers"
        }

        val body = translateLine(tokens.subList(2, tokens.size - 1))
        macros += name to body
    }
}

private val opsByToken = mutableMapOf(
    "+" to ::opPlus,
    "-" to ::opMinus,
    "*" to ::opTimes,
    "/" to ::opDiv,
    "dup" to ::opDup,
    "drop" to ::opDrop,
    "swap" to ::opSwap,
    "over" to ::opOver
)

private fun opPlus(s: Stack<Int>) {
    require(s.size > 1) {
        "Addition requires that the stack contain at least 2 values"
    }

    val result = s.sum()
    s.clear()
    s.push(result)
}

private fun opMinus(s: Stack<Int>) {
    require(s.size == 2) {
        "Subtraction requires that the stack contain at least 2 values"
    }

    val b = s.pop()
    val a = s.pop()
    s.push(a - b)
}

private fun opTimes(s: Stack<Int>) {
    require(s.size > 1) {
        "Multiplication requires that the stack contain at least 2 values"
    }

    val result = s.reduce(Int::times)
    s.clear()
    s.push(result)
}

private fun opDiv(s: Stack<Int>) {
    require(s.size == 2) {
        "Division requires that the stack contain at least 2 values"
    }

    val b = s.pop()

    require(b != 0) {
        "Division by 0 is not allowed"
    }

    val a = s.pop()
    s.push(a / b)
}

private fun opDup(s: Stack<Int>) {
    require(s.size > 0) {
        "Duplicating requires that the stack contain at least 1 value"
    }

    s.push(s.peek())
}

private fun opDrop(s: Stack<Int>) {
    require(s.size > 0) {
        "Dropping requires that the stack contain at least 1 value"
    }

    s.pop()
}

private fun opSwap(s: Stack<Int>) {
    require(s.size > 1) {
        "Swapping requires that the stack contain at least 2 values"
    }

    val a = s.pop()
    val b = s.pop()
    s.push(a)
    s.push(b)
}

private fun opOver(s: Stack<Int>) {
    require(s.size > 1) {
        "Overing requires that the stack contain at least 2 values"
    }

    val a = s.pop()
    val b = s.peek()
    s.push(a)
    s.push(b)
}
