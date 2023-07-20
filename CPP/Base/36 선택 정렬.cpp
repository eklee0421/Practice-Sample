#include <iostream>
using namespace std;

void selection_sort(int* arr) {	//선택 정렬
	
	int max = 0;
	int n = 0;

	for (int i = 10; i > 0; i--) {
		for (int j = 0; j < i; j++) {	//가장 큰 수 찾기
			if (arr[j] > max) {
				max = arr[j];
				n = j;
			}
		}
		arr[n] = arr[i-1];	//가장 큰 수와 자리를 교환한다
		arr[i-1] = max;
		n = 0;
		max = 0;
	}
}

int main() {
	
	int n = 10;
	
	int arr[10] = {};
	int sort_arr[10] = {};

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sort_arr[i] = arr[i];
	}

	selection_sort(sort_arr);
	
	//등수에 따라 학점 부여
	for (int i = 0; i < n; i++) {
		if (sort_arr[0] == arr[i]) {
			cout << "F" << " ";
		}
		else if (sort_arr[1] == arr[i]) {
			cout << "D" << " ";
		}
		else if (sort_arr[2] == arr[i]) {
			cout << "D+" << " ";
		}
		else if (sort_arr[3] == arr[i]) {
			cout << "C" << " ";
		}
		else if (sort_arr[4] == arr[i]) {
			cout << "C+" << " ";
		}
		else if (sort_arr[5] == arr[i]) {
			cout << "B" << " ";
		}
		else if (sort_arr[6] == arr[i]) {
			cout << "B+" << " ";
		}
		else if (sort_arr[7] == arr[i]) {
			cout << "A" << " ";
		}
		else if (sort_arr[8] == arr[i]) {
			cout << "A+" << " ";
		}
		else if (sort_arr[9] == arr[i]) {
			cout << "A+" << " ";
		}
	}
}
