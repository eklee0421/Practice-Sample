#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i = 0; i < commands.size(); i++){
        vector<int> copy = array;
        sort(copy.begin()+(commands[i][0]-1), copy.begin()+commands[i][1]);
        answer.push_back(copy[commands[i][0]+commands[i][2]-2]);
    }
    
    return answer;
}
