# 최소 신장 트리
def find(parent, a):
    if (parent[a] != a):
        parent[a] = find(parent, parent[a])
    return parent[a]


def union(parent, a, b):
    a = find(parent, a)
    b = find(parent, b)
    if (a < b):
        parent[b] = a
    else:
        parent[a] = b


n, m = map(int, input().split())
parent = [0] * (n + 1)
for i in range(1, n + 1):
    parent[i] = i

edges = []
for _ in range(m):
    a, b, c = map(int, input().split())
    edges.append((c, a, b))

edges.sort()
result = 0
last = 0  # 전체 그래프에서 2개의 최소 신장 트리를 만들어야 한다
# >> 최소 신장 트리를 찾고 간선 중 가장 비용이 큰 간선을 제거한다
for edge in edges:
    c, a, b = edge
    if find(parent, a) != find(parent, b):
        union(parent, a, b)
        result += c
        last = c

print(result - last)
