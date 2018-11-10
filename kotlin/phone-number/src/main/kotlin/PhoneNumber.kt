class PhoneNumber(s: String) {
    private val s: String

    init {
        this.s = s
    }

    val number: String?
        get() {
            val ds = s.filter(::isDigit)

            return if (Regex("^1?([2-9][0-9]{2}){2}[0-9]{4}$") matches ds)
                stripLeading1(ds)
            else
                null
        }
}

private fun isDigit(c: Char): Boolean =
    c >= '0' && c <= '9'

private fun stripLeading1(ds: String) =
    if (ds[0] == '1') ds.substring(1) else ds
