import scala.collection.mutable.Stack

object MatchingBrackets {
  private val Opener = Map(')' -> '(', ']' -> '[', '}' -> '{')

  def isPaired(xs: String): Boolean = {
    val open = new Stack[Char]()

    for (x <- xs) {
      if (Opener.values.exists(_ == x)) {
        open.push(x)
      } else if (Opener.keys.exists(_ == x)) {
        if (open.isEmpty || open.top != Opener(x)) return false
        open.pop()
      }
    }

    return open.isEmpty
  }
}
