#include <iostream>
using namespace std;

int main() {


//'\n': 한줄 내리기
cout << "안녕\n하세요" << endl;
  /*
    출력 결과:
    안녕
    하세요
  */
  

//'\t': tap 기능 (8칸)
 cout << "반갑\t습니다" << endl;
  /*
    출력 결과:
    반갑        습니다
  */
  
 
//'\r' : 커서의 포지션을 맨 앞으로 보냄 (보내진만큼 앞부분은 지워진다)
  cout << "공부하기\r싫어요" << endl;
  /*
    출력 결과:
     싫어요기
  */

//'\a': 출력시 소리가 남
cout << "소리가 \a나요" << endl;


}
