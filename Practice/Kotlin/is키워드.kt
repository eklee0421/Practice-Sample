fun main() {
    //기본형
    val a: Int = 128
    val b = a

    //참조형
    val c: Int? = a
    val d: Int? = a
    val e: Int? = c

    println(c==d) //true
    println(c===d) //false - c와 d는 다른 타입의 객체
    println(c===e) //true - c와 e는 같은 타입의 객체

    //is 키워드를 이용한 검사
    val num = 256
    if(num is Int){ //num이 Int형일 때
        print(num)
    }
    else if(num !is Int){   //num이 Int형이 아닐때, !(num is Int)와 동일
        print("Not a Int")
    }
    //256 출력

    /*
    아래 코드는 Kotlin: Incompatible types: Int and Double로 컴파일 오류
    
    val num2 = 256.1
    if(num2 is Int){ //num이 Int형일 때
        print(num)
    }
    else if(num2 !is Int){   //num이 Int형이 아닐때, !(num is Int)와 동일
        print("Not a Int")
    }
    //Not a Int
    */

}
