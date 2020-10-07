#include <string>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    for(int i = 0; i<s.size();i++){
        if(s[i] == '-' || s[i] == '+'){
            continue;
        }
        answer *= 10;
        answer += s[i]-'0';
    }
    
    if(s[0] == '-'){
            answer = 0 - answer;
    }
    
    return answer;
}
