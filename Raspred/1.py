for x1 in [0, 1]:
    for x2 in [0, 1]:
        for x3 in [0, 1]:
            for x4 in [0, 1]:
                for x5 in [0, 1]:
                    a = [x1, x2, x3, x4, x5].count(1) > 2
                    b = [int([x1, x2, x3].count(1) > 1), int([x2, x3, x4].count(1) > 1), int([x3, x4, x5].count(1) > 1)].count(1) > 1
                    print(a, b, '!!!' if a != b else "+++")