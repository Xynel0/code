import java.time.LocalDate
import java.time.format.TextStyle
import java.util.Locale

fun main() {
   var today = LocalDate.now()
	  var localeBR = Locale("pt", "BR")
   var weekday = today.dayOfWeek.getDisplayName(TextStyle.FULL, localeBR)
    var day = today.dayOfMonth
    var month = today.month.getDisplayName(TextStyle.FULL, localeBR)
    println("hoje é $weekday, dia $day de $month!")
}
