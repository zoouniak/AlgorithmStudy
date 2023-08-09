#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[500][500];
int height[257];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M, B;
	int input;
	cin >> N >> M >> B;
	int max = 0;
	int min = 257;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> input;
			map[i][j] = input;
			height[input]++;
			if (max < input) max = input;
			if (min > input) min = input;
		}
	}
	int count = 0;

	while (min < max) {
		if (height[min] <= B) {
			if (height[min] <= height[max] * 2) {
				count += height[min];
				B -= height[min];
				height[min + 1] += height[min];
				min++;
			}
			else {
				count += 2 * height[max];
				height[max - 1] += height[max];
				max--;
			}
		}
		else {
			count += 2 * height[max];
			B += height[max];
			height[max - 1] += height[max];
			max--;
		}
	}
	cout << count << " " << min;
}