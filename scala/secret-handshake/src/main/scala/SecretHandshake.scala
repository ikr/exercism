sealed abstract class Instruction(val bit: Int)
case class Action(override val bit: Int, text: String) extends Instruction(bit)
case class FlipOrder(override val bit: Int) extends Instruction(bit)

object SecretHandshake {
  val Menu = List(
    Action(1, "wink"),
    Action(2, "double blink"),
    Action(4, "close your eyes"),
    Action(8, "jump"),
    FlipOrder(16)
  )

  def commands(bits: Int) =
    Menu.foldLeft(List[String]())((result, instruction) =>
      if ((bits & instruction.bit) != 0) instruction match {
        case Action(_, text) => result ::: List(text)
        case FlipOrder(_)    => result.reverse
      }
      else result
    )
}
