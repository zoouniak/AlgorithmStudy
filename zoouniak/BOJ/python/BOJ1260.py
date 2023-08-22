from collections import deque


def dfs(graph, start):
    print(start, end=' ')
    visited[start] = 1
    for i in range(1, n + 1):
        if (visited[i] == 0 and graph[start][i] == 1):
            dfs(graph, i)


def bfs(graph, start):
    q = deque()
    q.append(start)
    visited[start] = 1
    print(start, end=' ')
    while (q):
        i = q.popleft()
        for v in range(1, n + 1):
            if visited[v] == 0 and graph[i][v] == 1:
                print(v, end=' ')
                q.append(v)
                visited[v] = 1


n, m, v = map(int, input().split())
graph = [[0] * (n + 1) for i in range(n + 1)]

for _ in range(m):
    i, j = map(int, input().split())
    graph[i][j] = graph[j][i] = 1

visited = [0] * (n + 1)
dfs(graph, v)
print()
visited = [0] * (n + 1)
bfs(graph, v)
