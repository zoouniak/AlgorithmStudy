#include <iostream>
#include <vector>
using namespace std;
vector<int> v;

void postOrder(int start, int end) {
	int idx = start + 1;
	if (start >= end) return;
	for (int i = start + 1; i < end; i++) {
		if (v[start] < v[idx]) break;
		idx++;
	}
	postOrder(start + 1, idx);
	postOrder(idx, end);
	cout << v[start] << '\n';
}
int main() {
	int n;
	while (true) {
		cin >> n;
		if (cin.eof()==true) break;
		v.push_back(n);
	}
	postOrder(0, v.size());
}