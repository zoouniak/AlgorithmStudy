#include <iostream>
#include <math.h>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	map<int, string> hash1;
	map<string, int> hash2;

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		string input;
		cin >> input;
		hash1.insert(make_pair(i, input));
		hash2.insert(make_pair(input, i));
	}
	for (int i = 0; i < M; i++) {
		string input;
		cin >> input;
		int num = 0;
		for (int j = 0; j < input.length(); j++) {
			if (isdigit(input[j]))
				num += (input[j] - '0') * pow(10, input.length() - 1 - j);
		}
		if (num != 0) cout << hash1[num] << '\n';
		else {
			cout << hash2[input] << '\n';
		}
	}
}