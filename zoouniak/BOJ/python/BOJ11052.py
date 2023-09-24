n = int(input())
card = list(map(int, input().split()))
card.insert(0, 0)
dp = card.copy()
for i in range(2, n + 1):
    for j in range(i + 1):
        dp[i] = max(dp[i], dp[i - j] + dp[j])
print(dp[n])
