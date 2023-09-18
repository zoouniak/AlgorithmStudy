n, m = map(int, input().split())
war = []
visited = [[False for _ in range(n)] for _ in range(m)]


def dfs(r, c):
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    global visited
    global cnt
    visited[r][c] = True
    for i in range(4):
        nx = r + dx[i]
        ny = c + dy[i]
        if 0 <= nx < m and 0 <= ny < n and war[nx][ny] == war[r][c] and not visited[nx][ny]:
            cnt += 1
            dfs(nx, ny)

for _ in range(m):
    war.append(list(input()))
black = 0
white = 0
b = 0
w = 0
for i in range(m):
    for j in range(n):
        cnt = 1
        if not visited[i][j]:
            dfs(i, j)
            if war[i][j] == 'W':
                w += cnt ** 2
            else:
                b += cnt ** 2

print(w, b, end=" ")
