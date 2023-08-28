#include <iostream>
using namespace std;

int main() {
	string str;
	cin >> str;

	string result = "";
	int count = 0;
	bool failed = false;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'X') count++;
		else {
			if (count % 2 == 0) {
				for (int j = 0; j < (count / 4); j++) {
					result += "AAAA";
				}
				for (int j = 0; j < (count % 4); j++) {
					result += "B";
				}
			}
			else failed = true;
			result += ".";
			count = 0;
		}
	}
	if (count % 2 == 0) {
		for (int j = 0; j < (count / 4); j++) {
			result += "AAAA";
		}
		for (int j = 0; j < (count % 4); j++) {
			result += "B";
		}
	}
	else failed = true;

	if (failed) cout << -1;
	else cout << result;
}