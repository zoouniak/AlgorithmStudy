import sys

input = sys.stdin.readline
n, m, k = map(int, input().split())
quest = [tuple(map(int, input().split())) for _ in range(m)]
answer = 0
arr = [0] * (n)


def combination(depth, start):
    if depth == n:
        result = 0
        a = set(arr)
        for i in quest:
            for j in i:
                if j not in a:
                    break
            else:
                result += 1
        global answer
        answer = max(answer, result)
        return

    for i in range(start, 2 * n + 1):
        arr[depth] = i
        combination(depth + 1, i + 1)


combination(0, 1)
print(answer)
