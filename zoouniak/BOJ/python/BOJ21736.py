from collections import deque

n, m = map(int, input().split())
campus = [[" "] * m for _ in range(n)]
visited = [[False] * m for _ in range(n)]


def bfs(x, y):
    result = 0
    q = deque()
    q.append([x, y])
    dx = [-1, 1, 0, 0]
    dy = [0, 0, 1, -1]
    while q:
        xy = q.pop()
        x = xy[0]
        y = xy[1]
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < m and not visited[nx][ny]:
                if campus[nx][ny] == 'P':
                    visited[nx][ny] = True
                    q.append([nx, ny])
                    result += 1
                elif campus[nx][ny] == 'O':
                    visited[nx][ny] = True
                    q.append([nx, ny])
    return result


meX = -1
meY = -1
for i in range(n):
    inputs = list(input())
    for j in range(m):
        campus[i][j] = inputs[j]
        if inputs[j] == 'I':
            meX = i
            meY = j
result = bfs(meX, meY)
print('TT' if result == 0 else result)
