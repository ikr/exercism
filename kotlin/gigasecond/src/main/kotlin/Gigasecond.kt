import java.time.LocalDate
import java.time.LocalDateTime

class Gigasecond {
    val date: LocalDateTime

    constructor(originDate: LocalDate) {
        date = gigaAdd(originDate.atStartOfDay())
    }

    constructor(originDateTime: LocalDateTime) {
        date = gigaAdd(originDateTime)
    }
}

private fun gigaAdd(t: LocalDateTime) =
    t.plusSeconds(1_000_000_000)
