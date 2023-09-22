n = int(input())
rect = []
for i in range(n):
    rect.append(list(map(int, input().split())))
dp = [[0 for _ in range(n)] for _ in range(n)]
dp[0][0] = rect[0][0]
for i in range(1, n):
    for j in range(len(rect[i])):
        if j == 0:
            dp[i][j] = dp[i - 1][j] + rect[i][j]
        elif j == len(rect[i]) - 1:
            dp[i][j] = dp[i - 1][j - 1] + rect[i][j]
        else:
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + rect[i][j]

print(max(dp[n - 1]))
