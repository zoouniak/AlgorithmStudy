import sys

input = sys.stdin.readline
n = int(input())

dp = [0] * 1000
dp[1] = 1
dp[2] = 2
for i in range(3, n + 1):
    dp[i] = dp[i - 2] + dp[i - 1]
# i-1까지 채워져있는 경우 + i-2까지 채워져있는 경우
print(dp[n] % 10007)
