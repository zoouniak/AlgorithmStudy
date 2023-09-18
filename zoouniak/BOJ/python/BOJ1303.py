n, m = map(int, input().split())
war = []
visited = [[False for _ in range(n)] for _ in range(m)]


def dfs(r, c, color):
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    global visited
    global white
    global black
    visited[r][c] = True
    if color == 'W':
        white += 1
    else:
        black += 1
    for i in range(4):
        nx = r + dx[i]
        ny = c + dy[i]
        if 0 <= nx < m and 0 <= ny < n and war[nx][ny] == color and not visited[nx][ny]:
            dfs(nx, ny, color)


for _ in range(m):
    war.append(list(input()))
black = 0
white = 0
b = 0
w = 0
for i in range(m):
    for j in range(n):
        if not visited[i][j] and war[i][j] == 'B':
            dfs(i, j, 'B')
            b += black ** 2
            black = 0
        elif not visited[i][j] and war[i][j] == 'W':
            dfs(i, j, 'W')
            w += white ** 2
            white = 0
print(w, b, end=" ")
