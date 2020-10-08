/*

setw(n)

n만큼의 공간을 만든 뒤 뒤에서 부터 출력물을 채운다 (라이브러리는 <iomanip>)
​

랜덤 수가 골고루 여러번 출력되는 프로그램이 좋은 랜덤 수를 만든 프로그램!(하나의 번호만 몰리면 예측 가능해진다)

*/


//1부터 6 사이의 랜덤 수를 60,000,000번 뽑은 다음 각각 몇 번 뽑혔는지 출력하는 프로그램


#include <iostream>
#include <cstdlib> 
#include <iomanip> 
#include <ctime> 
using namespace std; 

int main() { 
	srand(time(0)); 
	int f1, f2, f3, f4, f5, f6; 
	f1 = f2 = f3 = f4 = f5 = f6 = 0; 
	for (int i = 0; i < 60000000; i++) { 
		int n = rand() % 6 + 1; 
		switch (n) 		{
 		case 1: 
			f1++; break;
 		case 2: 
			f2++; break; 
		case 3: 
			f3++; break;
 		case 4: 
			f4++; break; 
		case 5: 
			f5++; break; 
		case 6: 
			f6++; break;
 		} 
	}

 	cout << setw(4) << "face" << setw(15) << "frequency" << endl;
 	cout << setw(4) << "1" << setw(15) << f1 << endl;
 	cout << setw(4) << "2" << setw(15) << f2 << endl;
 	cout << setw(4) << "3" << setw(15) << f3 << endl;
 	cout << setw(4) << "4" << setw(15) << f4 << endl; 
	cout << setw(4) << "5" << setw(15) << f5 << endl; 
	cout << setw(4) << "6" << setw(15) << f6 << endl;
 }
