#include <string>
using namespace std;

string solution(string s) {
    string answer = s;
    
    for(int i = 0; i < answer.size(); i++){
        int max = i;
        for(int j = i; j < answer.size(); j++){
            if(answer[max] < answer[j]){
                max = j;
            }
        }
        char c = answer[max];
        answer[max] = answer[i];
        answer[i] = c;
    }
    
    return answer;
}
