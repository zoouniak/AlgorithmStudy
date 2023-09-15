from collections import deque


def bfs(start, end):
    q = deque()
    global d
    global visited
    global result
    q.append([start, end])
    visited[start][end] = True
    result[start][end] = 0
    while q:
        k = q.popleft()
        x = k[0]
        y = k[1]
        for i in d:
            nx = x + i[0]
            ny = y + i[1]
            if 0 < nx <= n and 0 < ny <= n and not visited[nx][ny]:
                result[nx][ny] = min(1 + result[x][y], result[nx][ny])
                visited[nx][ny] = True
                q.append([nx, ny])


n, m = map(int, input().split())
x, y = map(int, input().split())
d = [[-2, -1], [-2, 1], [-1, -2], [-1, 2], [1, -2], [1, 2], [2, -1], [2, 1]]
result = [[987654321 for _ in range(n + 1)] for _ in range(n + 1)]
visited = [[False for _ in range(n + 1)] for _ in range(n + 1)]
bfs(x, y)
for _ in range(m):
    targetX, targetY = map(int, input().split())
    print(result[targetX][targetY])
