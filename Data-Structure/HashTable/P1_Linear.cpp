/*

Linear하게 해시 테이블에 저장
-> 만약 삽입하려는 곳에 이미 값이 있어서 충돌이 일어날 경우 다음 인덱스를 하나하나 살펴보며 빈 곳에 삽입한다

문제에서 인풋값이 작게 주어졌으므로, 인덱스의 처음으로 돌아가는 부분과
         NOITEM을 벗어난 이후에 값이 들어있는 경우는 없으므로 이 부분은 구현되어 있지 않다. (탐색시 NOITEM flag를 만나면 while문 )
*/

#include<iostream>
#include<vector>

#define MAX 353333
#define NOITEM 0		
#define ISITEM 1		
#define AVAILABLE 2		

using namespace std;

class cell {
public:
	int key;
	int value;
	int flag;
	cell() {
		key = -1;
		value = -1;
		flag = NOITEM;
	}
	~cell() {}
};
cell hashArr[MAX];
int probing = 1;

int hashfunc(int idx) {
	return idx % MAX;
}

//원소 
void tableInsertLinear(int key) {
	
	probing = 1;

	while (hashArr[hashfunc(hashfunc(key) + probing - 1)].flag == ISITEM) {
		probing += 1;
	}

	hashArr[hashfunc(hashfunc(key) + probing - 1)].key = key;
	hashArr[hashfunc(hashfunc(key) + probing - 1)].flag = ISITEM;

}

//원소 검색
void tableSearchLinear(int key) {

	probing = 1;

	while (hashArr[hashfunc(hashfunc(key) + probing - 1)].flag != NOITEM) {
		if (hashArr[hashfunc(hashfunc(key) + probing - 1)].key == key) {
			break;
		}

		probing += 1;
	}

	if (hashArr[hashfunc(hashfunc(key) + probing - 1)].flag == NOITEM) cout << 0 << " " << probing << endl;
	else cout << 1 << " " << probing << endl;
	
}

//원소 삭제하고 탐색 결과 출력
void tableDeleteLinear(int key) {

	probing = 1;

	while (hashArr[hashfunc(hashfunc(key) + probing - 1)].flag != NOITEM) {
		if (hashArr[hashfunc(hashfunc(key) + probing - 1)].key == key) {
			break;
		}

		probing += 1;
	}

	if (hashArr[hashfunc(hashfunc(key) + probing - 1)].flag == NOITEM) cout << 0 << " " << probing << endl;
	else
	{
		cout << 1 << " " << probing << endl;
		hashArr[hashfunc(hashfunc(key) + probing - 1)].flag = AVAILABLE;
		hashArr[hashfunc(hashfunc(key) + probing - 1)].key = -1;
	}


}

//테이블 초기화
void tableClear() {
	for (int i = 0; i < MAX; i++) {
		hashArr[i].key = -1;
		hashArr[i].value = -1;
		hashArr[i].flag = NOITEM;
	}
}

int main() {

	int test = 0;
	cin >> test;

	for (int T = 0; T < test; T++) {

		tableClear();

		int n = 0;
		cin >> n;
		for (int N = 0; N < n; N++) {
			int k = 0;
			cin >> k;
			tableInsertLinear(k);
		}

		int m = 0;
		cin >> m;
		for (int M = 0; M < m; M++) {
			int s = 0;
			cin >> s;
			tableDeleteLinear(s); //delete하는 함수
      //tableSearchLinear(s) //search하는 함수 
		}

	}

	return 0;
}
