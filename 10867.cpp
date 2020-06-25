#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int arr[100000] = {};
	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr, arr + n);

	for (int i = 0; i < n; i++) {
		if (arr[i] == arr[i + 1]) continue;
		cout << arr[i] << " ";
	}

	cout << endl;
}
