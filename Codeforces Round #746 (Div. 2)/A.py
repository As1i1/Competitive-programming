for _ in range(int(input())):
    n, h = map(int, input().split())
    a = list(map(int, input().split()))
    a1 = max(a)
    a.remove(a1)
    a2 = max(a)
    k = h // (a1 + a2)
    h -= (a1 + a2) * k
    k *= 2
    if h == 0:
        print(k)
    elif h > a1:
        k += 2
        print(k)
    else:
        k += 1
        print(k)