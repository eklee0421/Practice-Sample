/*
기존의 srand를 이용한 랜덤 수 설정은 보안에 취약하다
다음과 같은 방법은 보안이 조금 더 강화된 랜덤 수 설정 방법이다


라이브러리: <rand>
n부터 m 사이의 수 중 랜덤 수 뽑기
default_random_engine
변수명(static_cast<타입>(time(0)));
uniform_int_distribution<타입> 
클래스명(n, m);

cout << 클래스명(변수명);
*/

#include <iostream>
#include <ctime>
#include <iomanip>
#include <random>
using namespace std;

int main() {
	default_random_engine
		engine(static_cast<unsigned int>(time(0)));
	uniform_int_distribution<unsigned int> 
		randomInt(1, 6);

	for (int i = 1; i <= 20; i++) {
		cout << setw(5) << randomInt(engine);
		if (i % 5 == 0) {
			cout << endl;
		}
	}
}
