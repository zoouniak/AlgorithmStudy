def find(parent, a):
    if parent[a] != a:
        return find(parent, parent[a])
    return parent[a]


def union(parent, a, b):
    a = find(parent, a)
    b = find(parent, b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


n, m = map(int, input().split())
parent = [0] * (n + 1)

for i in range(1, n + 1):
    parent[i] = i

# m개의 연산 입력 받기
for _ in range(m):
    c, a, b = map(int, input().split())
    if c == 0:
        union(parent, a, b)
    elif c == 1:
        if find(parent, a) == find(parent, b):
            print("YES")
        else:
            print("NO")
