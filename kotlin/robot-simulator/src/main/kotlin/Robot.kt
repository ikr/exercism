class Robot(var gridPosition: GridPosition, var orientation: Orientation) {
    constructor() : this(GridPosition(0, 0), Orientation.NORTH)

    fun turnLeft() {}
    fun turnRight() {}
    fun advance() {}
    fun simulate(program: String) {}
}
