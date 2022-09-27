def check(x):
    flag_m = True
    flag_s = True
    slow = {}
    i = 0
    for x1 in [0, 1]:
        for x2 in [0, 1]:
            for x3 in [0, 1]:
                for x4 in [0, 1]:
                    slow[(x1, x2, x3, x4
                          )] = x[i]
                    i += 1


    for x1 in [0, 1]:
        for x2 in [0, 1]:
            for x3 in [0, 1]:
                for x4 in [0, 1]:
                    if slow[(x1, x2, x3, x4)] == slow[(1 - x1, 1 - x2, 1 - x3, 1 - x4)]:
                        flag_s = False
                        break


    for x1 in [0, 1]:
        for x2 in [0, 1]:
            for x3 in [0, 1]:
                for x4 in [0, 1]:
                    d1 = max(0, x1 - 1)
                    d2 = max(0, x2 - 1)
                    d3 = max(0, x3 - 1)
                    d4 = max(0, x4 - 1)
                    if not ((slow[(x1, x2, x3, x4)] <= slow[(d1, x2, x3, x4)] or d1 == x1)
                            and (slow[(x1, x2, x3, x4)] <= slow[(x1, d2, x3, x4)] or d2 == x2)
                            and (slow[(x1, x2, x3, x4)] <= slow[(x1, x2, d3, x4)] or d3 == x3)
                            and (slow[(x1, x2, x3, x4)] <= slow[(x1, x2, x3, d4)] or d4 == x4)):
                        flag_m = False
                        break

    return flag_m and flag_s


a = []
for i in range(1 << 16):
    tmp = []
    for j in range(16):
        if i & (1 << j):
            tmp.append(1)
        else:
            tmp.append(0)
    if check(tmp):
        a.append(str(tmp))

print('\n'.join(a))