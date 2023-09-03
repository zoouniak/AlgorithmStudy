#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void hanoi(int n, int from, int via, int to) {
	if (n == 1) {
		cout << from << " " << to << '\n';
	}
	else {
		hanoi(n - 1, from, to, via);
		cout << from << " " << to << '\n';
		hanoi(n - 1, via, from, to);
	}
}
int main() {
	int n;
	cin >> n;
	string k = to_string(pow(2, n));

	int x = k.find('.'); // pow�� return�� �Ǽ����̹Ƿ� �Ҽ��� ã��
	k = k.substr(0, x); // �Ҽ��� ���ڸ��� ������ �ϱ�
	k[k.length() - 1] -= 1; 

	cout << k << '\n';

	if (n <= 20) {
		hanoi(n, 1, 2, 3);
	}
}