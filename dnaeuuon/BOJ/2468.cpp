#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int map[101][101];
bool visited[101][101];
int N;
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int a, int b, int n)
{
	queue<pair<int, int>> q;
	q.push(make_pair(a, b));
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		visited[x][y] = true;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
			if (!visited[nx][ny] && map[nx][ny] > n)
			{
				q.push(make_pair(nx, ny));
				visited[nx][ny] = true;
			}
		}
	}
}

int main() 
{
	cin >> N;

	int maxInt = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int input;
			cin >> input;
			map[i][j] = input;
			if (maxInt < input) maxInt = input;
		}
	}
	int max = 0;
	
	for (int k = 0; k <= maxInt; k++)
	{
		int count = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				
				if (!visited[i][j] && map[i][j] > k)
				{
					bfs(i, j, k);
					count++;
				}
				if (max <= count) max = count;
			}
		}
		fill(visited[0], visited[100], false);
	}
	cout << max;
}
