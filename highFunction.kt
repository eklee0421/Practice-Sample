fun highFunc(sum : (Int, Int) -> Int, a:Int, b:Int):Int{
    return sum(a,b)
}

fun highFunc2(a:Int, b:Int, sum : (Int, Int) -> Int):Int{
    return sum(a,b)
}

fun main() {
   val result = highFunc({x,y -> x + y}, 1,3)
    println(result)

    val result2 = highFunc2(1,3) {x,y -> x+y}
    println(result2)
}
