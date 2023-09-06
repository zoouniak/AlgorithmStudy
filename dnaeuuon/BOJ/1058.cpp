#include <iostream>
using namespace std;
int map[51][51];
int answer; // 전역으로 선언하든지 초기화해주든지
int INF = 100000000;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++) {
            if (str[j] == 'Y') map[i][j] = 1;
            else map[i][j] = INF;
        }
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (map[i][j] <= 2) count++;
        }
        answer = max(answer, count);
    }
    cout << answer;
}