#include <iostream>
using namespace std;

int main() {
	
	for (int i = 2; i < 10; i++) {
			
	for (int j = 1; j < 10 ; j++){
		if (i == 5) {
			goto L1;  // L1이 선언되어 있는 곳으로 
		}
		cout << i << "X" << j << "=" << i * j << '\t';
		}
	cout << endl;
	}
L1:
}
