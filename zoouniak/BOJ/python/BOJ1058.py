n = int(input())
friend = []
second = [[] for _ in range(n)]
result = [[] for _ in range(n)]

for _ in range(n):
    friend.append(list(input()))

for i in range(n):
    for j in range(n):
        if friend[i][j] == 'Y':
            second[i].append(j)  # 두사람이 친구
            result[i].append(j)
            if len(second[i]) >= 2:
                for k in range(0, len(second[i]) - 1):  # A와 친구,B와 친구인 C존재
                    result[second[i][k]].append(j)
                    result[j].append(second[i][k])

max = 0
for i in range(n):
    result[i] = list(set(result[i]))
    if max < len(result[i]):
        max = len(result[i])

print(max)
