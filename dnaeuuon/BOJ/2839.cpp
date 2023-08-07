#include <iostream>
using namespace std;
int sugar[5001];
int main() {
	int N;
	cin >> N;
	
	sugar[3] = 1;
	sugar[5] = 1;

	for (int i = 6; i <= N; i++) {
		if (sugar[i - 3] != 0 && sugar[i - 5] != 0) {
			sugar[i] = 1 + min(sugar[i - 3], sugar[i - 5]);
		}
		else if (sugar[i - 3] != 0 && sugar[i - 5] == 0) {
			sugar[i] = 1 + sugar[i - 3];
		}
		else if (sugar[i - 3] == 0 && sugar[i - 5] != 0) {
			sugar[i] = 1 + sugar[i - 5];
		}
		else sugar[i] = 0;
	}
	if (sugar[N] == 0) cout << -1;
	else cout << sugar[N];
}