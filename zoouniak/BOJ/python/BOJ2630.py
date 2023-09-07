n = int(input())
paper = [[] for _ in range(n)]
for i in range(n):
    paper[i] = list(input().split())


def make(n, start, end):
    global white
    global blue
    color = paper[start][end]
    for i in range(n):
        for j in range(n):
            if paper[start + i][end + j] != color:
                make(n // 2, start, end)
                make(n // 2, start + (n // 2), end)
                make(n // 2, start, end + (n // 2))
                make(n // 2, start + (n // 2), end + (n // 2))
                return
    if color == '1':
        blue += 1
    else:
        white += 1


white = 0
blue = 0
make(n, 0, 0)
print(white)
print(blue)
