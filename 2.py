for x1 in [1, 0]:
    for x2 in [1, 0]:
        for x3 in [1, 0]:
            for x4 in [1, 0]:
                if sum([sum([x1, x2, x4]), sum([x1, x3, x4]), sum([x2, x3, x4])]) > 1:
                    print(1, end=' ')
                else:
                    print(0, end=' ')