#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<int> edge2[20001];
    
    for(vector<int> v: edge){
        edge2[v[0]].push_back(v[1]);
        edge2[v[1]].push_back(v[0]);
    }
    
    queue<int> visit;
    bool visited[20001] = { false, };
    
    visit.push(1);
    visited[1] = true;
    
    while(!visit.empty()){
        answer = visit.size();
        
        for(int i = visit.size(); i > 0; i--){
            int v = visit.front();
            visit.pop();

            for(int n: edge2[v]){
                if(!visited[n]){
                    visit.push(n);
                    visited[n] = true;
                }
            }
        }
    }
    
    return answer;
}
