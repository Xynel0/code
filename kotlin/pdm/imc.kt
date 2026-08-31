fun imc(args: Array<String>): String {
    var peso = args[0].toDouble()
    var altura = args[1].toDouble()
    var imcRes = peso/(altura*altura)
    return "%.2f".format(imcRes)
}

fun main(args: Array<String>) {    
    var imcResult = imc(args)
    println("O seu imc é $imcResult")
}
