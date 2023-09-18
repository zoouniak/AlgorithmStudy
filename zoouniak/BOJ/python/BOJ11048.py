n, m = map(int, input().split())
miro = []
for _ in range(n):
    miro.append(list(map(int, input().split())))
dp = [[0 for _ in range(m)] for _ in range(n)]
for i in range(n):
    for j in range(m):
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + miro[i][j]
# 한 번에 대각선으로 이동하는 것보다 2단계에 걸쳐 이동하는 것이 무조건 이득
print(dp[n - 1][m - 1])
