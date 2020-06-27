#include <string>
using namespace std;

int month[12]={31,29,31,30,31,30,31,31,30,31,30,31};

string solution(int a, int b) {
    
    int day = 0;
    for(int i=0; i < a - 1; i++){
        day += month[i];
    }
    day+=b;
    day%= 7;
    
    string answer = "";

    switch(day){
        case 1: answer = "FRI"; break;
        case 2: answer = "SAT"; break;
        case 3: answer = "SUN"; break;
        case 4: answer = "MON"; break;
        case 5: answer = "TUE"; break;
        case 6: answer = "WED"; break;
        case 0: answer = "THU"; break;
    }
    return answer;
}
