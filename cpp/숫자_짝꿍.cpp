#include <string>
#include <vector>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    
    int cnt_X[10] = { 0, }, cnt_Y[10] = { 0, };
    
    for(char c: X) cnt_X[c - '0']++;
    for(char c: Y) cnt_Y[c - '0']++;
    
    for(int i = 9; i > -1; i--){
        for(int j = 0; j < min(cnt_X[i], cnt_Y[i]); j++) answer.push_back(i + '0');
    }
    
    if(answer[0] == '0') answer = "0";
    
    if(answer.empty()) answer = "-1";
    
    return answer;
}
