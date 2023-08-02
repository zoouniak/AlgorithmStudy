#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int N;
	cin >> N;
	vector<int> minus;
	vector<int> plus;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		if (input >= 0) plus.push_back(input);
		else minus.push_back(input);
	}
	sort(plus.begin(), plus.end());
	sort(minus.begin(), minus.end());

	int result = 0;
	int size = minus.size();

	for (int i = 0; i < size - 1; i += 2) {
		result += (minus[i] * minus[i + 1]);
	}
	if ((minus.size() % 2) != 0) {
		if (plus.size() != 0 && plus[0] == 0) {
			plus.erase(plus.begin());
		}
		else result += minus[minus.size() - 1];
	}

	for (int i = plus.size() - 1; i > 0; i -= 2) {
		if (plus[i] == 0 || plus[i] == 1 || plus[i-1] == 1 || plus[i-1] ==0)  {
			result += (plus[i] + plus[i - 1]);
		}
		else {
			result += (plus[i] * plus[i - 1]);
		}
	}
	if ((plus.size() % 2) != 0)	result += plus[0];
	cout << result;
}