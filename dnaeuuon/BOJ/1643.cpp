#include <iostream>
#include <algorithm>
using namespace std;
int memorized[1000001];

int main() {
	int X;
	cin >> X;
	
	memorized[1] = 0;
	for (int i = 2; i <= X; i++) {
		memorized[i] = memorized[i - 1] + 1;
		if ((i % 3) == 0) {
			memorized[i] = min(memorized[i / 3] + 1, memorized[i]);
		}
		if ((i % 2) == 0) {
			memorized[i] = min(memorized[i / 2] + 1, memorized[i]);
		}
	}
	cout << memorized[X];
}