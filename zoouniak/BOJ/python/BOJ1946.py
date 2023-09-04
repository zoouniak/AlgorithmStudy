import sys

input = sys.stdin.readline
t = int(input())
for _ in range(t):
    lst = []
    n = int(input())
    for _ in range(n):
        lst.append(list(map(int, input().split())))
    lst.sort()
    cnt = 1
    Bgrade = lst[0][1]  # A 1등의 B성적.
    for i in range(1, n):
        if Bgrade > lst[i][1]:  # 나보다 A순위 높은 사람보다 B순위 높으면 ok
            cnt += 1
            Bgrade = lst[i][1]
    print(cnt)
