import sys

input = sys.stdin.readline
t = int(input())
for _ in range(t):
    n = int(input())
    person = [0 for _ in range(n + 1)]
    for _ in range(n):
        a, b = map(int, input().split())
        person[a] = b
    cnt = 1
    Bgrade = person[1]  # A 1등의 B성적.
    for i in range(1, n + 1):
        if Bgrade > person[i]:  # 나보다 A순위 높은 사람보다 B순위 높으면 ok
            cnt += 1
            Bgrade = person[i]
    print(cnt)
