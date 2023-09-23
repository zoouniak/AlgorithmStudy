n = int(input())
stair = []
for _ in range(n):
    stair.append(int(input()))
dp = [0 for _ in range(n)]
dp[0] = stair[0]
if n > 1:
    dp[1] = stair[0] + stair[1]
if n > 2:
    dp[2] = max(stair[1], stair[0]) + stair[2]

for i in range(3, n):
    dp[i] = max(stair[i] + dp[i - 2], stair[i - 1] + stair[i] + dp[i - 3])

print(dp[n - 1])
