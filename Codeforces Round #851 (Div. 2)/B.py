for  _ in range(int(input())):
    n = input()
    x, y = '', ''
    sx, sy = 0, 0
    for i in n:
        if int(i) % 2 == 0:
            x += str(int(i) // 2)
            y += str(int(i) // 2)
        else:
            if sx > sy:
                x += str(int(i) // 2)
                y += str(int(i) // 2 + 1)
            else:
                x += str(int(i) // 2 + 1)
                y += str(int(i) // 2)
        sx += int(x[-1])
        sy += int(y[-1])
    while x[0] == '0' and len(x) > 1:
        x = x[1:]
    while y[0] == '0' and len(y) > 1:
        y = y[1:]
    print(x, y)