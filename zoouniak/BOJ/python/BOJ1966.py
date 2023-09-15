from collections import deque

t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    q = deque()
    for i in range(n):
        q.append(i)
    importance = list(map(int, input().split()))
    result = []
    while q:
        i = q.popleft()
        cnt = 0
        for j in q:
            if importance[j] > importance[i]:
                q.append(i)
                break
            else:
                cnt += 1
        if cnt == len(q):
            result.append(i)
    print(result.index(m) + 1)
