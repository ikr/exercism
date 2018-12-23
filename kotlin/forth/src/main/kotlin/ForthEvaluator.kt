import java.util.Stack
import kotlin.text.toInt

class ForthEvaluator {
    private val stack = Stack<Int>()

    fun evaluateProgram(p : List<String>): List<Int> {
        p.forEach(this::evalLine)
        return stack.toList()
    }

    private fun evalLine(l: String) {
        l.split(" ").forEach({token ->
            when (token) {
                "+" -> sPlus(stack)
                "-" -> sMinus(stack)
                else -> sNum(stack, token)
            }
        })
    }
}

private fun sPlus(s: Stack<Int>) {
    require(s.size > 1) {
        "Addition requires that the stack contain at least 2 values"
    }

    val result = s.sum()
    s.clear()
    s.push(result)
}

private fun sMinus(s: Stack<Int>) {
    require(s.size == 2) {
        "Subtraction requires that the stack contain at least 2 values"
    }

    val b = s.pop()
    val a = s.pop()
    s.push(a - b)
}

private fun sNum(s: Stack<Int>, token: String) {
    s.push(token.toInt())
}
