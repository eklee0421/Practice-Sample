#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int test = 0;
	cin >> test;

	while (test--) {
		
		string s, r;
		cin >> s >> r;

		int Rcapital[26] = {};	//문자열 r 영역에 있는 문자의 수
		int Rsmall[26] = {};

		int Wcapital[26] = {};	//문자열 s의 윈도우 영역에 있는 문자의 수
		int Wsmall[26] = {};

		for (int i = 0; i < r.size(); i++) {
			if (r[i] >= 'A' && r[i] <= 'Z') Rcapital[r[i] - 'A']++;
			else Rsmall[r[i] - 'a']++;
		}

		int start = -1;
		int end = -1;
		int min = s.size()+1;
		int cnt = 0;

		while (start != s.size() && end != s.size()) {
			if (cnt < r.size()) {
				end++;
				if (s[end] >= 'A' && s[end] <= 'Z') {
					Wcapital[s[end] - 'A']++;
					if (Rcapital[s[end] - 'A'] >= Wcapital[s[end] - 'A']) cnt++;	//우리에게 필요한 문자라면 찾은 문자 수 증가
				}
				else {
					Wsmall[s[end] - 'a']++;
					if (Rsmall[s[end] - 'a'] >= Wsmall[s[end] - 'a'] ) cnt++;
				}
			}
			else if(cnt == r.size()){	//s에서 r을 모두 찾은 경우
				if (min > (end - start)) min = end - start;	//최소 문자열인지 확인하고 업데이트
				start++;	//start를 한칸 옆으로 옮겨서
				if (s[start] >= 'A' && s[start] <= 'Z') {
					Wcapital[s[start] - 'A']--;
					if (Rcapital[s[start] - 'A'] > Wcapital[s[start] - 'A']) cnt--;	//필요한 문자라면 cnt 감소
				}
				else {
					Wsmall[s[start] - 'a']--;
					if (Rsmall[s[start] - 'a'] > Wsmall[s[start] - 'a']) cnt--;
				}
						
			}
		}
		
		if (min == s.size()+1) cout << 0 << endl;
		else	cout << min << endl;
	}

}
