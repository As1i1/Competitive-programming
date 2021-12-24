from math import gcd
for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    g_n, g_c = a[0], a[1]
    for i in range(2, n, 2):
        g_n = gcd(g_n, a[i])
    for i in range(3, n, 2):
        g_c = gcd(g_c, a[i])
    flag1, flag2 = True, True
    for i in range(0, n, 2):
        if a[i] % g_c == 0:
            flag2 = False
    for i in range(1, n, 2):
        if a[i] % g_n == 0:
            flag1 = False
    if flag1:
        print(g_n)
    elif flag2:
        print(g_c)
    else:
        print(0)