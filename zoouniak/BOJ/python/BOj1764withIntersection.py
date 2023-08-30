import sys

input = sys.stdin.readline
n, m = map(int, input().split())

listen = set()
see = set()

for _ in range(n):
    listen.add(input().rstrip())
for _ in range(m):
    see.add(input().rstrip())

ls = list(listen.intersection(see))
ls.sort()
print(len(ls))
for i in ls:
    print(i)
