/*

이름 공간(namespace) : 이름 충돌을 막기 위해 등장한 문법적 요소로 공간에 이름을 붙여주는 행위

*/

#include <iostream>

namespace Hybird {                                         //Hybird 라는 이름 공간을 만들어줌
	void HybFunc(void) {
		std::cout << "안녕" << std::endl;
		std::cout << "잘가" << std::endl;
	}
}

int main() {

using Hybird::HybFunc;                             //Hybird 안에 있는 HybFunc라는 함수를 사용하겠다
	HybFunc();

}
