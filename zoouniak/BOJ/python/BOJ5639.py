import sys

pre = []  # 전위순회
while True:
    try:
        pre.append(int(input()))
    except:
        break

sys.setrecursionlimit(10 ** 6)


def post(start, end):
    if start > end:
        return
    mid = end + 1
    for i in range(start + 1, end + 1):
        if pre[i] > pre[start]:  # 오른쪽 트리 시작이 i
            mid = i
            break
    post(start + 1, mid - 1)  # 왼쪽
    post(mid, end)  # 오른쪽
    print(pre[start])  # 루트


post(0, len(pre) - 1)
