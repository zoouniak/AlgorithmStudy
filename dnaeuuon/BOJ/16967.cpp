#include <iostream>
using namespace std;
int B[1000][1000];
int A[300][300];
int H, W, X, Y;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> H >> W >> X >> Y;
	for (int i = 0; i < (H + X); i++) {
		for (int j = 0; j < (W + Y); j++) {
			int input;
			cin >> input;
			B[i][j] = input;
			if (i < H && j < W) A[i][j] = input;
		}
	}
	for (int i = X; i < H; i++) {
		for (int j = Y; j < W; j++) {
			A[i][j] = B[i][j] - A[i - X][j - Y];
		}
	}
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << A[i][j] << " ";
		}
		cout << '\n';
	}
}