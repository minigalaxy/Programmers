#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    int N = maps.size(), M = maps[0].size();
    
    queue<pair<int, int>> visit;
    bool visited[100][100] = { false, };
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!visited[i][j] && maps[i][j] != 'X'){
                int food = 0;
                
                visit.push(make_pair(i, j));
                visited[i][j] = true;
                
                while(!visit.empty()){
                    pair<int, int> coord = visit.front();
                    visit.pop();
                    
                    food += maps[coord.first][coord.second] - '0';
                    
                    for(int i = 0; i < 4; i++){
                        int nx = coord.first + dx[i];
                        int ny = coord.second + dy[i];
                        
                        if(nx > -1 && nx < N && ny > -1 && ny < M && !visited[nx][ny] && maps[nx][ny] != 'X'){
                            visit.push(make_pair(nx, ny));
                            visited[nx][ny] = true;
                        }
                    }
                }
                
                answer.push_back(food);
            }
        }
    }
    
    sort(answer.begin(), answer.end());
    
    if(answer.empty()) answer.push_back(-1);
    
    return answer;
}
