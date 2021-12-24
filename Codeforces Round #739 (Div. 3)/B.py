for _ in range(int(input())):
    a, b, c = map(int, input().split())
    m = abs(a - b) * 2
    if max([a, b, c, m]) == m:
        if c + m // 2 > m:
            print((c + m // 2) % m)
        else:
            print(c + m // 2)
    else:
        print(-1)