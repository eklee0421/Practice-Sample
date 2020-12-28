fun sum(a:Int, b:Int):Int{  //최상위 함수
    var sum = a + b
    return sum
}

fun main() {    //최상위 (top-level) 함수
    var a = 20
    var b = 10
    println(sum(a,b))

    println(sum(1,2))

}
