n = int(input())
grape = []
for _ in range(n):
    grape.append(int(input()))
dp = [0 for _ in range(n)]
dp[0] = grape[0]
if n > 1:
    dp[1] = grape[0] + grape[1]
limit = 2
if n > 2:
    dp[2] = max(grape[0] + grape[1], grape[1] + grape[2], grape[0] + grape[2])
for i in range(3, n):
    dp[i] = max(grape[i - 1] + grape[i] + dp[i - 3], grape[i] + dp[i - 2], dp[i - 1])

print(dp[n - 1])
