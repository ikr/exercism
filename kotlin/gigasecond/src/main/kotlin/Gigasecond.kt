import java.time.LocalDate
import java.time.LocalDateTime

class Gigasecond {
    constructor(origin: LocalDate) {
    }

    constructor(origin: LocalDateTime) {

    }

    val date: LocalDateTime
        get() = LocalDateTime.MIN
}
