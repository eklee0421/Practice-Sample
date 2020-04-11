/*
iostream 라이브러리를 #include를 통해 가지고 온다.

using namespace std; 를 사용하면,
코드 앞에 일일이 std::를 붙여야 하는 번거로움을 줄일 수 있다
*/

#include <iostream>
using namespace std;    //일일이 std::를 붙이지 않아도 된다

int main() {

	cout << "Hello world" << endl;      //Hello world 출력

	system("pause");                    //비주얼 스튜디오에서 실행 동작을 일시정시 시킴
	return 0;
}
