#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string str;
	cin >> str;
	int num = str[0] - '0';
	int zeroCnt = 0, oneCnt = 0;
	if (num == 0) zeroCnt++;
	else oneCnt++;
	for (int i = 0; i < str.length() - 1; i++) {
		num = str[i] - '0';
		if (num == 0) {
			if (num != (str[i + 1] - '0')) oneCnt++;
		}
		else {
			if (num != (str[i + 1] - '0')) zeroCnt++;
		}
	}
	cout << min(zeroCnt, oneCnt) << '\n';
}