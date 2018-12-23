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
                else -> sNum(stack, token)
            }
        })
    }
}

private fun sPlus(s: Stack<Int>) {
    val result = s.sum()
    s.clear()
    s.push(result)
}

private fun sNum(s: Stack<Int>, token: String) {
    s.push(token.toInt())
}
