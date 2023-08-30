n, m = map(int, input().split())
see = {}
result = []
for _ in range(n):
    see[input()] = 1

for _ in range(m):
    name = input()
    if see.get(name) == 1:  # O(1)
        result.append(name)

result.sort()
print(len(result))
for name in result:
    print(name)
