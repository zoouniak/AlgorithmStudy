// bfs
using namespace std;
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
// int X, Y;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
bool visited[101][101];

int bfs(vector<string> maps, int a, int b, int height, int width) {
    queue<pair<int, int>> q;
    q.push(make_pair(a, b));
    int result = 0;
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        result += maps[x][y] - '0';
        
        visited[x][y] = true;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= height || ny >= width) continue;
            
            if(!visited[nx][ny] && maps[nx][ny] != 'X') {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = true;
            }
        }
    }
    return result;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    // X = map[0].size();
		// Y = map.size();

    for(int i = 0; i < maps.size(); i++) {
        for(int j = 0; j < maps[i].size(); j++) {
            if(maps[i][j] != 'X' && !visited[i][j]) {
                answer.push_back(bfs(maps, i, j, maps.size(), maps[i].size()));
            }
        }
    }
                       
    if(answer.empty()) answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}
