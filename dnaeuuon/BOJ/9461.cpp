#include <iostream>
using namespace std;
long long padovan[101];

int main() {
	padovan[1] = padovan[2] = padovan[3] = 1;
	for (int i = 4; i < 101; i++) {
		padovan[i] = padovan[i -2] + padovan[i - 3];
	}
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int input;
		cin >> input;
		cout << padovan[input] << endl;
	}
}