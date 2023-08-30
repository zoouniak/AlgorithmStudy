n = int(input())


def hanoi(n, frm, by, to):
    global num
    if (n == 1):
        str_list.append(str(frm) + ' ' + str(to) + '\n')
        num += 1
    else:
        hanoi(n - 1, frm, to, by)
        str_list.append(str(frm) + ' ' + str(to) + '\n')
        num += 1
        hanoi(n - 1, by, frm, to)


num = 0
str_list = []
hanoi(n, 1, 2, 3)
print(num)
print(''.join(str_list))
