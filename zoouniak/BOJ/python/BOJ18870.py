n = int(input())
x = list(map(int, input().split()))
# 나보다 작은 원소의 개수
a = x[:]
x.sort()
result = {x[0]: 0}

for i in range(1, len(x)):  # 0부터 리스트 길이까지
    if x[i] == x[i - 1]:
        result[x[i]] = result[x[i - 1]]
    else:
        result[x[i]] = result[x[i - 1]] + 1
for i in range(0, len(a)):
    a[i] = result[a[i]]
    print(a[i], end=" ")
