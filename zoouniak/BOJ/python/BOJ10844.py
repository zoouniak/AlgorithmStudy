n = int(input())

# 길이가 n인 인접한 모든 자리의 차이가 1인 수
dp = [[0 for _ in range(10)] for _ in range(n + 1)]
dp[1][0] = 0
for i in range(1, 10):
    dp[1][i] = 1
for i in range(2, n + 1):
    for j in range(10):
        if j == 0:
            dp[i][j] = dp[i - 1][j + 1]
        elif j == 9:
            dp[i][j] = dp[i - 1][j - 1]
        else:
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1]
result = 0
for count in dp[n]:
    result += count
print(result % 1000000000)
