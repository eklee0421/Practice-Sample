/*
상수: 한 번 정해지면 바꿀 수 없는 값으로, 일반 변수와 구분해주기 위해 대문자로 변수명을 적어준다

방법 1) const int MIN = 5;
type은 지정 가능 하며, 반드시 선언시에 값을 지정해줘야 한다

방법 2) enum Status {CONTINUE, WON = 200, LOST};

이렇게 생성하면, 상수에 넣어줄 수 있는 값은 정수만 가능하다
아무 값도 지정해주지 않으면 맨 앞부터 0, 1, 2.. 의 값이 자동으로 들어가며
위와 같이 앞의 상수만 값을 지정해주면, 해당 초기화 값으로 지정된다
LOST의 값은 자동으로 201이 된다

--

enum class
enum class Status : unsigned int {CONTINUE, WON , LOST};

명시적으로 타입 줄 수 있지만 꼭 적어야하는 것은 아니다(적지 않으면 int로 생성)
기존 enum과는 다르게 class 안의 지역 상수이기 때문에
반드시 ::을 사용하여 불러야 한다
다른 enum에서 같은 상수명이 사용되었을 때 혼동되는 것을 막기 위함이며(실수 방지),
때문에 다른 enum의 상수와 비교가 불가능 하다

방법 3) #define MAX = 100
c에서 쓰던 상수 지정 방법으로 cpp에서는 사용하지 않는다
*/

#include <iostream>
using namespace std;

int main () {

	const int MIN = 5;

	enum Status { CONTINUE , WON = 200, LOST };

#define MAX

	cout << "MIN:" << MIN << endl;
	cout << "CONTINUE:" << CONTINUE << endl;
	cout << "WON:" << WON << endl;
	cout << "LOST:" << LOST << endl;
}
