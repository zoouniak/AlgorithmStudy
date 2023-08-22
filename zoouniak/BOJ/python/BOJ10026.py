from collections import deque


def bfs_normal(color, start, end):
    q = deque()
    q.append([start, end])
    visited[start][end] = True
    while q:
        xy = q.pop()
        x = xy[0]
        y = xy[1]
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if (0 <= nx < n and 0 <= ny < n and pic[nx][ny] == color and not visited[nx][ny]):
                q.append([nx, ny])
                visited[nx][ny] = True

def bfs_colorblind(color,start,end):
    q = deque()
    q.append([start,end])
    visited[start][end]=True
    while q:
        xy = q.pop()
        x = xy[0]
        y = xy[1]
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if (0 <= nx < n and 0 <= ny < n and not visited[nx][ny]):
                if((color=='R' or color=='G') and (pic[nx][ny]=='R' or pic[nx][ny]=='G')):
                    q.append([nx, ny])
                    visited[nx][ny] = True
                if(color=='B' and pic[nx][ny]=='B'):
                    q.append([nx, ny])
                    visited[nx][ny] = True


n = int(input())
pic = [[' '] * n for i in range(n)]
for i in range(n):
    s = input()
    for j in range(n):
        pic[i][j] = s[j]

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
visited = [[False] * n for _ in range(n)]
color = {'R', 'G', 'B'}
count_normal=0

for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            bfs_normal(pic[i][j], i, j)
            count_normal+=1

print(count_normal,end=" ")
visited = [[False] * n for _ in range(n)]
count_blind =0
for i in range(n):
    for j in range(n):
        if not visited[i][j]:
            bfs_colorblind(pic[i][j], i, j)
            count_blind+=1
print(count_blind)
