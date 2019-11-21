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

int hashfunc2(int idx) {
	return (17 - (idx % 17));
}


void tableInsertLinear(int key) {

	probing = 1;

	while (hashArr[hashfunc(hashfunc(key) + probing - 1)].flag == ISITEM) {
		probing += 1;
	}

	hashArr[hashfunc(hashfunc(key) + probing - 1)].key = key;
	hashArr[hashfunc(hashfunc(key) + probing - 1)].flag = ISITEM;

}


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


void tableInsertDouble(int key) {
	probing = 1;

	while (hashArr[hashfunc(hashfunc(key) + (probing - 1) * hashfunc2(key))].flag == ISITEM) {
		probing += 1;
	}

	hashArr[hashfunc(hashfunc(key) + (probing - 1) * hashfunc2(key))].key = key;
	hashArr[hashfunc(hashfunc(key) + (probing - 1) * hashfunc2(key))].flag = ISITEM;

}


void tableSearchDouble(int key) {
	probing = 1;

	while (hashArr[hashfunc(hashfunc(key) + (probing - 1) * hashfunc2(key))].flag != NOITEM) {
		if (hashArr[hashfunc(hashfunc(key) + (probing - 1) * hashfunc2(key))].key == key) {
			break;
		}

		probing += 1;
	}

	if (hashArr[hashfunc(hashfunc(key) + (probing - 1) * hashfunc2(key))].flag == NOITEM) cout << 0 << " " << probing << endl;
	else cout << 1 << " " << probing << endl;

}


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
			tableInsertDouble(k);
		}

		int m = 0;
		cin >> m;
		for (int M = 0; M < m; M++) {
			int s = 0;
			cin >> s;
			tableSearchDouble(s);
		}

	}

	return 0;
}
