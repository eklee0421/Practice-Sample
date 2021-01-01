fun main() {

    var result: Int

    // 일반 변수에 람다식 할당
    val multi = {x: Int, y: Int -> x * y}
    // 람다식이 할당된 변수는 함수처럼 사용 가능
    result = multi(10, 20)
    println(result)

    val multi1: (Int, Int) -> Int = {x: Int, y: Int -> x * y} // 생략되지 않은 전체 표현
    val multi2 = {x: Int, y: Int -> x * y}  // 선언 자료형 생략
    val multi3: (Int, Int) -> Int = {x, y -> x * y} // 람다식 매개변수 자료형의 생략

    val greet: ()->Unit = { println("Hello World!") }
    val square: (Int)->Int = { x -> x * x }
}
