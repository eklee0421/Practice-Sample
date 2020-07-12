#include <vector>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    
    if(arr.size() == 1){
        answer.push_back(-1);
    }
    else{
        int min = 0;
        for(int i = 0; i < arr.size(); i++){
            if(arr[min] > arr[i]) min = i;
        }
        
        for(int i = 0; i < arr.size(); i++){
            if(min == i) {
                continue;
            }
            else{
                 answer.push_back(arr[i]);
            }
        }
    }
    
    return answer;
}
