n, k = map(int, input().split())
money = []
for _ in range(n):
    money.append(int(input()))
money.sort(reverse=True)
coin = 0
for i in range(n):
    coin += k // money[i]
    k = k % money[i]
    if k == 0:
        break
print(coin)
