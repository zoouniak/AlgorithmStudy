import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    mbti = list((input().split()))
    if n > 32:
        print(0)
    else:
        min = 987654321
        for i in range(n-2):
            for j in range(i + 1,n-1):
                for z in range(j + 1,n):
                    cnt = 0
                    for k in range(4):
                        if mbti[i][k] != mbti[j][k]:
                            cnt += 1
                        if mbti[i][k] != mbti[z][k]:
                            cnt += 1
                        if mbti[z][k] != mbti[j][k]:
                            cnt += 1
                    if cnt < min:
                        min = cnt
        print(min)
