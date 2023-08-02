#include <iostream>
#include <algorithm>
using namespace std;
int list[100][100];
int min_list[100];

int main() {
	int N, M;
	cin >> N >> M;
	int max = 0;
	for (int i = 0; i < N; i++) {
		
		int min = 10001;
		for (int j = 0; j < M; j++) {
			cin >> list[i][j];
			if (min > list[i][j]) {
				min = list[i][j];
			}
		}
		min_list[i] = min;
		if (max < min_list[i]) {
			max = min_list[i];
		}
	}
	cout << max << endl;
}