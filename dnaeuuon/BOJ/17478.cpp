#include <iostream>
using namespace std;
int n;

void chat(int N, string str) {
	cout << str;
	cout << "\"����Լ��� ������?\"\n";
	if (N == 0) {
		cout << str + "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
	}
	else {
		cout << str + "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
		cout << str + "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
		cout << str + "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
		str += "____";
		chat(N - 1, str);
		cout << str + "��� �亯�Ͽ���.\n";
	}
}

int main() {
	cin >> n;
	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	chat(n, "");
	cout << "��� �亯�Ͽ���.";
}