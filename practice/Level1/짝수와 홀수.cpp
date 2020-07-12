#include <string>
using namespace std;

string solution(int num) {
    string answer = "";
    if(num % 2){    //홀수라면
        answer = "Odd";
    }
    else{   //홀수라면
        answer = "Even";
    }
    return answer;
}
