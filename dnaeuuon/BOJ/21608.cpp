#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[21][21];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

int main() {
	int N;
	cin >> N;
	vector<int> like[21 * 21]; // 1부터 N^2의 번호

	for (int i = 0; i < N * N; i++) { // N^2 만큼 입력 받기
		int student;
		cin >> student;
		for (int j = 0; j < 4; j++) {
			int number;
			cin >> number;
			like[student].push_back(number);
		}
		int maxLike = 0;
		int maxEmpty = 0;
		int indexX = -1;
		int indexY = -1;

		for (int j = N - 1; j >= 0; j--) { // 행
			for (int k = N - 1; k >= 0; k--) { // 열
				int cnt = 0;
				int empty = 0;
				if (map[j][k] == 0) {
					for (int n = 0; n < 4; n++) { // 상하좌우
						int nx = j + dx[n];
						int ny = k + dy[n];
						if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
						for (int m = 0; m < 4; m++) {
							if (like[student][m] == map[nx][ny]) cnt++;
						}
						if (map[nx][ny] == 0) empty++;
					}
					if (maxLike < cnt) {
						maxLike = cnt;
						maxEmpty = empty;
						indexX = j;
						indexY = k;
					}
					else if (maxLike == cnt && maxEmpty < empty) {
						maxEmpty = empty;
						indexX = j;
						indexY = k;
					}
					else if (maxLike == cnt && maxEmpty == empty) {
						indexX = j;
						indexY = k;
					}
				}
			}
		}
		map[indexX][indexY] = student;
	}
	
	int satisfy = 0;
	for (int j = 0; j < N; j++) {
		for (int k = 0; k < N; k++) {
			int result = 0;
			for (int n = 0; n < 4; n++) {
				int nx = j + dx[n];
				int ny = k + dy[n];
				if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
				for (int m = 0; m < 4; m++) {
					if (like[map[j][k]][m] == map[nx][ny]) result++;
				}
			}
			switch (result)
			{
			case 1:
				satisfy += 1;
				break;
			case 2:
				satisfy += 10;
				break;
			case 3:
				satisfy += 100;
				break;
			case 4:
				satisfy += 1000;
				break;
			default:
				break;
			}
		}
	}
	cout << satisfy;
}