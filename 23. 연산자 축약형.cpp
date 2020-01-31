//연산자를 축약하려 쓸 수 있다

#include <iostream>
using namespace std;

int main() {
	int n = 10;
	int m = 20;
	n *= m + 2;         // n = n*(m+2)           //우선순위에 주의한다
	cout << n << endl;

	int k = 1;
	int s = k++;        //s를 출력하는 순간에는 k값이 증가하지 않았다
  //K++;에서, ++을 지나와야 값이 증가한다는 것에 유의!
	cout << "s= " << s << ", k= " << k << endl;


	int j = 1;
	int i = ++j;        //i를 출력하는 순간에 이미 j값이 증가되어 있다
	cout << "i= " << i << ", j= " << j << endl;

	return 0;
}
