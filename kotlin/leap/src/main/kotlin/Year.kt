class Year(_value: Int) {
    val value = _value

    val isLeap: Boolean
    get() = (value % 4 == 0 && value % 100 != 0) || (value % 400 == 0)
}
