from collections import deque

n, k = map(int, input().split())

visited = [False for _ in range(100001)]
loc = [100000 for _ in range(100001)]


def bfs(t):
    q = deque()
    q.append(t)
    visited[t] = True
    loc[t] = 0
    while q:
        x = q.popleft()
        for i in (x + 1, x - 1, 2 * x):
            if (0 <= i <= 100000) and not visited[i]:
                loc[i] = min(loc[i], loc[x] + 1)
                visited[i] = True
                q.append(i)


bfs(n)
print(loc[k])
