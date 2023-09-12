cnt = 1
while True:
    s = list(input())
    if s[0] == '-':
        exit()
    stack = []
    for i in range(0, len(s)):
        if s[i] == '{':
            stack.append("{")
        else:

            if len(stack) > 0 and stack[len(stack) - 1] == "{":
                stack.pop()
            else:
                stack.append("}")
    answer = 0
    while len(stack) > 0:
        c = stack.pop()
        if c == "{":
            if stack[len(stack) - 1] == "{":
                answer += 1
            else:
                answer += 2
            stack.pop()
        else:
            if stack[len(stack) - 1] == "}":
                answer += 1
            stack.pop()
    print(str(cnt) + ". " + str(answer))
    cnt += 1
