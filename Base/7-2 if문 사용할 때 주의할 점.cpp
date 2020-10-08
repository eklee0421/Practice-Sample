/*

다음과 같이 조건문에 a=b라고 넣으면 b값을 a에 넣으라는 뜻으로, 0이 아닌 수를 넣으면 계속 참으로 인식한다
(단순 비교 뿐만 아니라 b의 데이터를 a에 넣는 연산까지 실행)


따라서 a와 b의 값이 같은지 여부를 알고 싶다면 a==b 라고 조건을 넣어야 한다

*/

#include <iostream>
using namespace std;

int main(){
  int a= 20;
  int b= 30;
	
  if (a == b) {                      
      	cout << "같다" << endl;
	  }

  if (a = b) {                      
      	cout << "같았으면 좋겠다" << endl;
	  }
  
  }
  // 같았으면 좋겠다를 출력
