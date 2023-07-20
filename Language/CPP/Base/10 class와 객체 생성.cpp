#include <iostream>
using namespace std;

class Gradebook {                   //class 생성

public:                             //클래스 외부에서 접근 가능
	void displayMsg() {
		cout << "Welcome the Grade Book!" << endl;
		return;
	}

	void test1() {
		cout << "test1" << endl;
	}

private:                              //클래스 외부에서 접근 불가능
	void test2() {
		cout << "test2" << endl;
	}
};

void test() {                        //글로벌 함수
	cout << "test" << endl;
}

int main() {

        test();                      //글로벌 함수 불러옴

	int test;                    //함수와 같은 이름의 변수 생성은 하지 않는 것이 좋다 
	Gradebook gb;                //클래스를 통해 객체 생성 (stack 에서 생성)
	
	gb.displayMsg();             //객체 안의 함수 불러오기
	gb. test1();

	//gb.test2();                //private는 반환할 수 없음 
}
