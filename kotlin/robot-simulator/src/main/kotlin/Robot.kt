class Robot(var gridPosition: GridPosition, var orientation: Orientation) {
    constructor() : this(GridPosition(0, 0), Orientation.NORTH)

    fun turnLeft() {
        orientation = when (orientation) {
            Orientation.NORTH -> Orientation.WEST
            Orientation.EAST -> Orientation.NORTH
            Orientation.SOUTH -> Orientation.EAST
            Orientation.WEST -> Orientation.SOUTH
        }
    }

    fun turnRight() {
        orientation = when (orientation) {
            Orientation.NORTH -> Orientation.EAST
            Orientation.EAST -> Orientation.SOUTH
            Orientation.SOUTH -> Orientation.WEST
            Orientation.WEST -> Orientation.NORTH
        }
    }

    fun advance() {
        gridPosition = gridPosition.apply(advanceDelta(orientation))
    }

    fun simulate(program: String) {
        program
            .forEach {
                require(it in setOf('L', 'R', 'A')) { "Program $program is invalid" }

                when (it) {
                    'L' -> turnLeft()
                    'R' -> turnRight()
                    'A' -> advance()
                }
            }
    }
}

private fun advanceDelta(orientation: Orientation): Delta =
    when (orientation) {
        Orientation.NORTH -> Delta(0, 1)
        Orientation.EAST -> Delta(1, 0)
        Orientation.SOUTH -> Delta(0, -1)
        Orientation.WEST -> Delta(-1, 0)
    }

private data class Delta(val x: Int, val y: Int)

private fun GridPosition.apply(delta: Delta): GridPosition =
    GridPosition(x + delta.x, y + delta.y)
