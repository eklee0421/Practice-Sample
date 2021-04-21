fun sum1(a:Int, b:Int):Int{  //최상위 함수
    var sum = a + b
    return sum
}

fun sum2(a:Int,b:Int) = a + b

fun max(a:Int, b:Int):String{
    return if (a>b) "a" else "b"
}

fun outfun(name: String): Unit{ //반환값이 없는 경우 - Unit은 생략가능!
    println("Name: $name")
    //return Unit 이 동작하고 있는 것
}

fun main() {    //최상위 (top-level) 함수
    var a = 20
    var b = 10
    println("sum1 : " + sum1(a,b))
    println("sum2 : " + sum2(a,b))
    println("max : " + max(a,b))

    println("sum1 : " + sum1(1,2))
    println("sum2 : " + sum2(1,2))
    println("max : " + max(1,2))

    outfun("gildong")
    
    /*
    [출력결과]
    sum1 : 30
    sum2 : 30
    max : a
    sum1 : 3
    sum2 : 3
    max : b
    Name: gildong
     */
}
