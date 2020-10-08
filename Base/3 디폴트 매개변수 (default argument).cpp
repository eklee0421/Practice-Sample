/*

디폴트 매개 변수 : 전달되지 않은 인자를 대신하기 위한 기본 값이 설정되어 있는 변수

선언과 동시에 디폴트 값을 설정해준다.

이후 값을 따로 넣지 않으면 디폴트 값이 들어간다.

*/

#include <iostream>
using namespace std;

int area(int height = 1, int width = 1);           //디폴트 값은 프로토 타입에 넣기

int main () {

	cout << area() << endl;                    //height와 width 모두 디폴트 값
	cout << endl;
  
  cout << area(5) << endl;                   //height=5, width는 디폴트 값
  cout << endl;
	
  cout << area(4, 5) << endl;                //height=4, width=5
}

int area(int height, int width) {
	cout << "height: " << height << "\nwidth: ";
	return  width;
}



/*
참조)

- 위치 기반 Argument : 숫자를 앞에서부터 하나씩 채운다 ex) C++, C언어 등
- 키워드 Argument: (변수 = 데이터)를 하나하나 적어준다 ex) 파이썬 등 

int area(int a, int b) {}             //함수 선언 시에 디폴트 값을 설정해주지 않은 경우

int main() {
 area(4,5)            //위치 기반 Argument
 area(a=4, b=5)       //키워드 기반 Argument
}

*/
