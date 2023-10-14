a = 30
b = 60

mx = -10000
x, y, z, w, v, t = 0, 0, 0, 0, 0, 0
for x1 in range(a, b):
    for x2 in range(a, b):
        for x3 in range(a, b):
            for x4 in range(a, b):
        # for x5 in range(a, b):
            # for x6 in range(a, b):
                # res = ((x1 * x2 * x3 * x4 * x5 * x6) /
                #        ((a + x1) * (x1 + x2) * (x2 + x3) * (x3 + x4) * (x4 + x5) * (x5 + x6) * (x6 + b)))
                res = ((x1 * x2 * x3 * x4) / ((a + x1) * (x1 + x2) * (x2 + x3) * (x3 + x4) * (x4 + b)))
                if res > mx:
                    mx = res
                    x = x1
                    y = x2
                    z = x3
                    w = x4
                    # v = x5
                    # t = x6
print(x, y, z, w, v, t)
