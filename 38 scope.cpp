/*
글로벌 변수 : 모든 지역에 영향을 미치며, 지역 변수 안에 같은 이름의 변수가 생성되면 hidden 된다

지역 변수: 변수가 선언된 지역 안에서만 영향을 미치며, 지역 밖을 빠져나올 때 변수를 지우기 때문에 다시 들어가면 변수를 새로 생성한다(변수 값이 초기화 됨)

static 변수: 프로그램 실행 할 때 단 한 번 선언되며, 모든 프로그램이 종료되기 전까지 사라지지 않는다
따라서 다시 불러와도 초기화 되지 않고 기존 값을 유지하고 있다 
*/

#include <iostream>
using namespace std;
void useLocal();
void useStatic();
void useGlobal();

int x = 1; // 글로벌 변수

int main() {

	cout << x << endl; //1

	int x = 5;
	cout << x << endl; //5

	{
		int x = 10;
		cout << x << endl; //10
		cout << ::x << endl; //1
	}

	cout << x << endl; //5
	cout << ::x << endl; //글로벌 하게 scope를 잡아준다 --> 1을 찍음 //1

	cout << "=======================" << endl;
	useLocal();
	useStatic();
	useGlobal();
	
	cout << "=======================" << endl;
	useLocal();
	useStatic();
	useGlobal();

	system("pause");
}

void useLocal() { //지역변수
	int x = 25;
	cout <<"Local: " << x << endl;
	x++;
	cout << "Local: " << x << endl;
}

void useStatic() { // static한 지역변수
	static int x = 100;
	cout << "Static: " << x << endl;
	x++;
	cout << "Static: " << x << endl;
}

void useGlobal() {
	cout << "Global: " << x << endl;
	x++;
	cout << "Global: " << x << endl;
}
