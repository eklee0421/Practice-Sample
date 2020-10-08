/*

클래스 내부에서는 어디에든 접근 가능하다

private: 외부에서 접근 불가능
public: 외부에서 접근 가능

*/

#include <iostream>
#include <string>
using namespace std;

class GradeBook {
private:                            //클래스 내부에서는 접근 가능 하지만 외부에서는 불가능
	string name;                //멤버 변수

public:                             //클래스 내외부에서 접근 가능
	void setName(string n) {    //멤버 함수
		name = n;
	}
	string getName() {
		return name;
	}
	void display() {
		cout << "display 과목명: " << name << endl;
	}
};

int main() {
	GradeBook gb;
        //gd.getName("AAA");        //출력은 가능하나, 이런 방식은 보안에 취약하다

	cout << "입력: ";

	string msg;
	getline(cin, msg);

	gb.setName(msg);
	gb.display();

	cout << "getName 과목명: "<< gb.getName() << endl;

}
