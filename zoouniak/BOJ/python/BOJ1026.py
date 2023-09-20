n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

a.sort(reverse=True)  # a의 젤 큰거와 b의 젤 작은거,,
b.sort()
result = 0
for i in range(n):
    result += a[i] * b[i]
print(result)
