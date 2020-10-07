#include <string>
using namespace std;

string solution(string s) {
    string answer = s;
    bool b = 1;
    for(int i = 0; i < s.size(); i++){
        if(answer[i] == ' '){
            b = 1;
        }
        else if(b){  //짝수라면
            answer[i] = toupper(answer[i]);
            b = 0;
        }
        else{
             answer[i] = tolower(answer[i]);
            b = 1;
        }
    }
    
    return answer;
}
