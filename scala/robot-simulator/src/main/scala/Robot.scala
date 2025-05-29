object Bearing extends Enumeration {
  type A = Value
  val North, East, South, West = Value
}

case class Robot(bearing: Bearing.A, coordinates: (Int, Int)) {
  def turnRight(): Robot = turn(1)
  def turnLeft(): Robot = turn(-1)

  def advance(): Robot = {
    val (x, y) = coordinates
    val newCoordinates = bearing match {
      case Bearing.North => (x, y + 1)
      case Bearing.East  => (x + 1, y)
      case Bearing.South => (x, y - 1)
      case Bearing.West  => (x - 1, y)
    }

    Robot(bearing, newCoordinates)
  }

  def simulate(xs: String): Robot =
    xs.foldLeft(this)((r: Robot, c: Char) =>
      c match {
        case 'L' => r.turnLeft()
        case 'R' => r.turnRight()
        case 'A' => r.advance()
      }
    )

  private def turn(delta: Int): Robot = {
    val newBearing = Bearing(
      (bearing.id + delta + Bearing.values.size) % Bearing.values.size
    )
    Robot(newBearing, coordinates)
  }
}
