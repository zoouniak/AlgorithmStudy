r, c, t = map(int, input().split())
room = [[] for _ in range(r)]
for i in range(r):
    room[i] = list(map(int, input().split()))
air = []
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]


def dust():
    after = [[0 for _ in range(c)] for _ in range(r)]
    for i in range(r):
        for j in range(c):
            if room[i][j] == -1:
                air.append([i, j])
            elif room[i][j] > 0:
                spread = 0
                amount = room[i][j] // 5
                for d in range(4):
                    nx = i + dx[d]
                    ny = j + dy[d]
                    if 0 <= nx < r and 0 <= ny < c and room[nx][ny] != -1:
                        spread += 1
                        after[nx][ny] += amount
                room[i][j] = room[i][j] - amount * spread
    for i in range(r):
        for j in range(c):
            room[i][j] += after[i][j]


def fresh():
    startX = air[0][0]
    for i in range(startX - 1, 0, -1):
        room[i][0] = room[i - 1][0]
    for i in range(0, c - 1):
        room[0][i] = room[0][i + 1]
    for i in range(0, startX):
        room[i][c - 1] = room[i + 1][c - 1]
    for i in range(c - 1, 0, -1):
        room[startX][i] = room[startX][i - 1]
    room[startX][1] = 0
    room[startX][0] = -1

    startX = air[1][0]
    for i in range(startX + 1, r - 1):
        room[i][0] = room[i + 1][0]
    for i in range(0, c - 1):
        room[r - 1][i] = room[r - 1][i + 1]
    for i in range(r - 1, startX, -1):
        room[i][c - 1] = room[i - 1][c - 1]
    for i in range(c - 1, 0, -1):
        room[startX][i] = room[startX][i - 1]
    room[startX][1] = 0
    room[startX][0] = -1


for _ in range(t):
    dust()
    fresh()

result = 0
for i in range(r):
    for j in range(c):
        if room[i][j] > 0:
            result += room[i][j]
print(result)
