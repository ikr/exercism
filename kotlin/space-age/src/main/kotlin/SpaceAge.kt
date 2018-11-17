import kotlin.math.round

class SpaceAge(seconds: Long) {
    private val seconds: Double
    init { this.seconds = seconds.toDouble() }

    fun onEarth(): Double = roundAge(onEarthRaw())
    fun onMercury(): Double = roundAge(onEarthRaw() / 0.2408467)
    fun onVenus(): Double = roundAge(onEarthRaw() / 0.61519726)
    fun onMars(): Double = roundAge(onEarthRaw() / 1.8808158)
    fun onJupiter(): Double = roundAge(onEarthRaw() / 11.862615)
    fun onSaturn(): Double = roundAge(onEarthRaw() / 29.447498)
    fun onNeptune(): Double = roundAge(onEarthRaw() / 164.79132)
    fun onUranus(): Double = roundAge(onEarthRaw() / 84.016846)

    private fun onEarthRaw(): Double =
        seconds / 31557600
}

private fun roundAge(x: Double): Double =
    round(x * 100) / 100
