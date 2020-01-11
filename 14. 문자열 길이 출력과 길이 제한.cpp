/*

string의 문자열 길이 출력
=> 방법 1) (변수).length()
=> 방법 2) (변수).size() 

문자열 길이 제한
=> (변수).substr(n번째부터, n개 만큼 자르기)

*/

#include <iostream>
#include <string>
using namespace std;

int main() {

	string str = "abcde123fgh";
	cout << str.length() << endl;
	cout << str.size() << endl;			//보통 size()를 더 많이 사용
	
	string msg = str.substr(5, 3);                 //(변수).substr(n번째부터, n개 만큼 자르기)
	cout << msg << endl;

}
