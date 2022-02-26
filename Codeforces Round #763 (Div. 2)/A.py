for _ in range(int(input())):
    n, m, xc, yc, xb, yb = map(int, input().split())
    xc, yc, xb, yb = xc - 1, yc - 1, xb - 1, yb - 1
    row = [-1 for i in range(n)]
    col = [-1 for j in range(m)]
    t = 0
    dx, dy = 1, 1
    while row[xb] == -1 and col[yb] == -1:
        row[xc] = t
        col[yc] = t
        if xc == n - 1:
            dx = -1
        elif xc == 0:
            dx = 1
        if yc == m - 1:
            dy = -1
        elif yc == 0:
            dy = 1
        t += 1
        xc += dx
        yc += dy
    print(t - 1)