using namespace std;

int solution(int num) {
    int answer = 0;
    
    while(num != 1){
        if(num % 2 == 1){    //홀수라면
            num = num * 3 + 1;
        }
        else{   //짝수라면
            num = num / 2;
        }
        
        answer++;
        if(answer == 500){
            answer = -1;
            break;
        }
    }
    
    return answer;
}
