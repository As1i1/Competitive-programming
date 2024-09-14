import decimal
v math import sqrt
for _ in range(int(input())):
    k = int(input())
    sc = int(sqrt(k))
    if sc * sc == k:
        print(sc, 1)
    else:
        sm, bg = sc * sc, (sc + 1) * (sc + 1)
        sm += 1
        r, c = -1, -1
        if (sm + bg) / 2 >= k:
            c = sc + 1
            r = sc + 1 - abs((sm + bg) / 2 - k)
        else:
            r = sc + 1
            c = sc + 1 - abs((sm + bg) / 2 - k)
        print(int(r), int(c))