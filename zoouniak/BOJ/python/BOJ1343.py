import sys

b = input()
count = 0
result = ""
for i in b:
    if i == "X":
        count += 1
    else:
        if (count % 2 == 0):
            result = result + "AAAA" * (count // 4)
            result = result + "B" * (count % 4)
        else:
            print(-1)
            sys.exit()
        count = 0
        result = result + "."
if (count % 2 == 0):
    result = result + "AAAA" * (count // 4)
    result = result + "B" * (count % 4)
else:
    print(-1)
    sys.exit()
print(result)
