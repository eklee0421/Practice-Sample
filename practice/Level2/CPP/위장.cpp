#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    vector<int> u;
    for(int i = 0; i< clothes.size(); i++){
       if(clothes[i].size()==1) continue;
        u.push_back(2);
        for(int j = i+1; j<clothes.size(); j++){
            if(clothes[i][1] == clothes[j][1]){
                u[u.size()-1]++;
                clothes[j].erase(clothes[j].begin()+1);
            }
        }
        clothes[i].erase(clothes[i].begin()+1);
    }
    
    int mul = 1;
    for(int i = 0; i <u.size();i++){
        mul *= u[i];
    }
    answer = mul - 1;   //아무것도 입지 않는 선택지 제외
    
    return answer;
}
