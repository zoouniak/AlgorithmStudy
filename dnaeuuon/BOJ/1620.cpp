#include <iostream>
#include <math.h>
using namespace std;
string str[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		string input;
		cin >> input;
		str[i] = input;
	}
	for (int i = 0; i < M; i++) {
		string input;
		cin >> input;
		int num = 0;
		for (int j = 0; j < input.length(); j++) {
			if(isdigit(input[j]))
				num += (input[j] - '0') * pow(10, input.length() - 1 - j);
		}
		if (num != 0) cout << str[num] << '\n';
		else {
			for (int j = 1; j <= N; j++) {
				int result = str[j].compare(input);
				if (result == 0) {
					cout << j << '\n';
					break;
				}
			}
		}
	}
}