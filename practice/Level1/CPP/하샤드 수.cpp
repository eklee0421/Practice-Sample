using namespace std;

bool solution(int x) {
    bool answer = true;
    
    int y = 0;
    int copyX = x;
    while(copyX){
        y += copyX % 10;
        copyX /= 10;
    }
    if(x%y) answer = false;   
    return answer;
}
