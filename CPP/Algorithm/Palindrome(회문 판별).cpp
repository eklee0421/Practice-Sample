#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int test = 0;	//테스트 케이스의 수
	cin >> test;

	while (test--) {
		string s;	//문자열 s
		cin >> s;
		
		bool N_pal = 0;	//문자열 s가 회문이면 0, 아니면 1

		for (int i = 0; i < s.size(); i++) {
			s[i] = tolower(s[i]); //대문자를 소문자로 교환.
		}
		
		int i = 0;	//맨 앞부터 시작
		int j = s.size() - 1;	//맨 뒤부터 시작
		while (i<j) {
			if (s[i] < 'a' || s[i] > 'z') { i++; continue; }
			if (s[j] < 'a' || s[j] > 'z') { j--; continue; }

			if (s[i] != s[j]) {
				N_pal = 1;
				break;
			}

			i++; j--;
		}

		if(N_pal) cout << "NO\n";
		else cout << "YES\n";
	
	}
}
