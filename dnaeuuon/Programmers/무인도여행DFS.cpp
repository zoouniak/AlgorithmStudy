using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int X, Y;
bool visited[101][101];

int dfs(vector<string> maps, int x, int y, int result) {
    visited[x][y] = true;
    result += maps[x][y] - '0';
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= Y || ny >= X) continue; 
        if(!visited[nx][ny]) {
            if(maps[nx][ny] != 'X') {
                visited[nx][ny] = true;
                result = dfs(maps, nx, ny, result);
            }
        }
    }
    return result;
}

vector<int> solution(vector<string> maps) {
    vector<int> answer;
    Y = maps.size();
    X = maps[0].size();

    for(int i = 0; i < maps.size(); i++) {
        for(int j = 0; j < maps[i].size(); j++) {
            int result = 0;
            if(maps[i][j] != 'X' && !visited[i][j]) {
                result += dfs(maps, i, j, result);
                answer.push_back(result);
            }
        }
    }
    if(answer.empty()) answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}
