/*
생성자 : 객체(멤버 필드)를 초기화 하는 역할
default(initializing) constructor (묵시적 생성자)
생성자를 따로 선언하지 않아도 컴파일 하며 자동으로 생성된다
 
GradeBook( ){
}

explicit constructor (명시적 생성자)

내 손으로 직접 초기화 시켜주는 것

방법 1)
 GradeBook(string n) {
name = n
}

방법 2) 
GradeBook(string n)
: name(n) {
}

*/

#include <iostream>
#include <string>
using namespace std;

class GradeBook {
private: 
	string name;				//멤버 필드는 아무 곳에나 생성해도 괜찮음

public: 
	explicit GradeBook(string n)	        //명시적인 생성자
		:name(n) {   
		}
		
	void setName(string n) {	
		name = n;
	}
	string getName() {
		return name;
	}
	void display() {
		cout << "과목명: " << name << endl;
	}
};

int main() {
	
	GradeBook gb("C++");
	gb.display();

	string msg;
	getline(cin, msg);
	gb.setName(msg);
	gb.display();

	cout << gb.getName() << endl;

	return 0;
}
