#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;
	int left = 0;
	int right = 0;
	int middle = str.length() / 2;

	for (int i = 0; i < middle; i++) {
		left += str[i] - '0';
		right += str[middle + i] - '0';
	}
	if (left == right) cout << "LUCKY" << endl;
	else cout << "READY" << endl;
}