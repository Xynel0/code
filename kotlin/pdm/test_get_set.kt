class Pessoa (){
    var peso:Double = 0.0
    	set(value){
            if (value >= 0)
            	field = value
        }
    var altura:Double = 0.0
    	set(value){
            if (value >= 0)
            	field = value
        }
    var IMC:Double = 0.0
    	get() = peso / (altura*altura)
}

fun main(){
    val p = Pessoa()
    p.peso = 130.0
    p.altura = 1.70
    p.peso = -30.0
    println ("Peso: "+p.peso)
	println ("IMC: %.2f".format(p.IMC))
}
