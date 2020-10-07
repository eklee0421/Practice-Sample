using namespace std;

int solution(int n) {
    int answer = n-1;
    bool arr[1000001]={};
    
    for(int i = 2; i<=n; i++){
        if(arr[i] == 1) continue;
        for(int j = 2; j<=n; j++){
            if(j*i > n) break;
            if(arr[j*i] == 0){
                arr[j*i]=1;
                answer--;
            }
        }
    }
    
    return answer;
}
