fun main() {
    var str1 : String? = "Hello Kotlin" // 널 가능한 문자열 자료형
    println("str1: $str1 length: ${str1!!.length}")  // str1이 null인지 체크하지 않음

    str1 = null
    println("str1: $str1")

    println("str1: $str1 length: ${str1?.length}")  // str1을 세이프 콜로 안전하게 호출

}
