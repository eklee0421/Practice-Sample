fun main(){
    val userName: String = "Kildong"    //불변형 변수
    var userName2: String = "Kildong"    //가변형 변수
    userName2 = "inha"

    println("username: $userName")
    println("username2: $userName2")

    var cnt : Int = 1
    var cnt2 = 2    //타입 제거해도 추론되어 선언됨

    println("$cnt $cnt2")
}
