import org.scalatest.funsuite.AnyFunSuite
import org.scalatest.matchers.should.Matchers

/** @version 2.2.0 */
class RobotSimulatorTest extends AnyFunSuite with Matchers {

  test(
    "A robot is created with a position and a direction - Robots are created with a position and direction"
  ) {
    Robot(Bearing.North, (0, 0)) should be(Robot(Bearing.North, (0, 0)))
  }

  test(
    "A robot is created with a position and a direction - Negative positions are allowed"
  ) {
    Robot(Bearing.South, (-1, -1)) should be(Robot(Bearing.South, (-1, -1)))
  }

  test(
    "rotates the robot's direction 90 degrees clockwise - does not change the position"
  ) {
    Robot(Bearing.North, (0, 0)).turnRight().coordinates should be((0, 0))
  }

  test(
    "rotates the robot's direction 90 degrees clockwise - changes the direction from north to east"
  ) {
    Robot(Bearing.North, (0, 0)).turnRight().bearing should be(Bearing.East)
  }

  test(
    "rotates the robot's direction 90 degrees clockwise - changes the direction from east to south"
  ) {
    Robot(Bearing.East, (0, 0)).turnRight().bearing should be(Bearing.South)
  }

  test(
    "rotates the robot's direction 90 degrees clockwise - changes the direction from south to west"
  ) {
    Robot(Bearing.South, (0, 0)).turnRight().bearing should be(Bearing.West)
  }

  test(
    "rotates the robot's direction 90 degrees clockwise - changes the direction from west to north"
  ) {
    Robot(Bearing.West, (0, 0)).turnRight().bearing should be(Bearing.North)
  }

  test(
    "rotates the robot's direction 90 degrees counter-clockwise - does not change the position"
  ) {
    Robot(Bearing.North, (0, 0)).turnLeft().coordinates should be((0, 0))
  }

  test(
    "rotates the robot's direction 90 degrees counter-clockwise - changes the direction from north to west"
  ) {
    Robot(Bearing.North, (0, 0)).turnLeft().bearing should be(Bearing.West)
  }

  test(
    "rotates the robot's direction 90 degrees counter-clockwise - changes the direction from west to south"
  ) {
    Robot(Bearing.West, (0, 0)).turnLeft().bearing should be(Bearing.South)
  }

  test(
    "rotates the robot's direction 90 degrees counter-clockwise - changes the direction from south to east"
  ) {
    Robot(Bearing.South, (0, 0)).turnLeft().bearing should be(Bearing.East)
  }

  test(
    "rotates the robot's direction 90 degrees counter-clockwise - changes the direction from east to north"
  ) {
    Robot(Bearing.East, (0, 0)).turnLeft().bearing should be(Bearing.North)
  }

  test(
    "moves the robot forward 1 space in the direction it is pointing - does not change the direction"
  ) {
    Robot(Bearing.North, (0, 0)).advance().bearing should be(Bearing.North)
  }

  test(
    "moves the robot forward 1 space in the direction it is pointing - increases the y coordinate one when facing north"
  ) {
    Robot(Bearing.North, (0, 0)).advance().coordinates should be((0, 1))
  }

  test(
    "moves the robot forward 1 space in the direction it is pointing - decreases the y coordinate by one when facing south"
  ) {
    Robot(Bearing.South, (0, 0)).advance().coordinates should be((0, -1))
  }

  test(
    "moves the robot forward 1 space in the direction it is pointing - increases the x coordinate by one when facing east"
  ) {
    Robot(Bearing.East, (0, 0)).advance().coordinates should be((1, 0))
  }

  test(
    "moves the robot forward 1 space in the direction it is pointing - decreases the x coordinate by one when facing west"
  ) {
    Robot(Bearing.West, (0, 0)).advance().coordinates should be((-1, 0))
  }

  test(
    "Where R = Turn Right, L = Turn Left and A = Advance, the robot can follow a series of instructions and end up with the correct position and direction - instructions to move west and north"
  ) {
    Robot(Bearing.North, (0, 0)).simulate("LAAARALA") should be(
      Robot(Bearing.West, (-4, 1))
    )
  }

  test(
    "Where R = Turn Right, L = Turn Left and A = Advance, the robot can follow a series of instructions and end up with the correct position and direction - instructions to move west and south"
  ) {
    Robot(Bearing.East, (2, -7)).simulate("RRAAAAALA") should be(
      Robot(Bearing.South, (-3, -8))
    )
  }

  test(
    "Where R = Turn Right, L = Turn Left and A = Advance, the robot can follow a series of instructions and end up with the correct position and direction - instructions to move east and north"
  ) {
    Robot(Bearing.South, (8, 4)).simulate("LAAARRRALLLL") should be(
      Robot(Bearing.North, (11, 5))
    )
  }
}
