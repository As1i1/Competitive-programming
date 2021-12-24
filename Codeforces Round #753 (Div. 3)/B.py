for _ in range(int(input())):
    x, n = map(int, input().split())
    t = 4 * (n // 4) + 1
    n = n % 4
    while n:
        if x % 2 == 0:
            x -= t
        else:
            x += t
        t += 1
        n -= 1
    print(x)