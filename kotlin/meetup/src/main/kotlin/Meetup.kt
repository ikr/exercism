import java.time.DayOfWeek
import java.time.LocalDate
import java.time.Month
import java.time.Year

class Meetup(month: Int, year: Int) {
    private val month: Int
    private val year: Int

    init {
        this.month = month
        this.year = year
    }

    fun day(dow: DayOfWeek, sch: MeetupSchedule): LocalDate {
        val dows = monthDays().filter { it.dayOfWeek == dow }

        return when (sch) {
            MeetupSchedule.FIRST -> dows[0]
            MeetupSchedule.SECOND -> dows[1]
            MeetupSchedule.THIRD -> dows[2]
            MeetupSchedule.FOURTH -> dows[3]
            MeetupSchedule.LAST -> dows.last()
            MeetupSchedule.TEENTH -> dows.find { isTeen(it.dayOfMonth) }
        } ?: throw IllegalStateException()
    }

    private fun monthDays(): List<LocalDate> =
        (1..Month.of(month).length(Year.of(year).isLeap()))
            .map { LocalDate.of(year, month, it) }
}

private fun isTeen(x: Int): Boolean =
    x > 12 && x < 20
