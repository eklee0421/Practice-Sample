#include <string>
using namespace std;

string solution(string s, int n) {
    string answer = s;
    
    for(int i = 0; i < s.size(); i++){
        if(answer[i] == ' '){
            continue;
        }
        else if(answer[i] >= 'a' && answer[i] <= 'z'){
            if(answer[i] + n > 'z'){
                answer[i] = 'a' + (n-('z' - answer[i])) -1;
            }
            else{
                answer[i]+= n;
            }
        }
        else if(answer[i] >= 'A' && answer[i] <= 'Z'){
            if(answer[i] + n > 'Z'){
                 answer[i] = 'A' + (n-('Z' - answer[i])) - 1;
            }
            else{
                answer[i]+= n;
            }
        }
    }
    
    return answer;
}
