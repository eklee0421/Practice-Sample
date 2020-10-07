#include <cmath>
using namespace std;

long long solution(long long n) {
    long long answer = sqrt(n);
    if(answer * answer == n){
        answer++;
        answer *= answer;
    }
    else{
        answer = -1;
    }
    
    return answer;
}
