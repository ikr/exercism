import java.time.DayOfWeek
import java.time.LocalDate

class Meetup(month: Int, year: Int) {
    init {}

    fun day(dow: DayOfWeek, sch: MeetupSchedule): LocalDate =
        LocalDate.MIN
}
