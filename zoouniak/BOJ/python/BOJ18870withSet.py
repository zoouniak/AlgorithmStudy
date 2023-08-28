import sys
input = sys.stdin.readline
n = int(input())

lst = list(map(int, input().split()))

unique_elements = sorted(set(lst))
unique_dict = {element: i for i, element in enumerate(unique_elements)}

print(unique_dict)