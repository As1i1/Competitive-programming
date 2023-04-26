for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    c1 = a.count(2)
    c2 = 0
    for i in range(n):
        if a[i] == 2:
            c2 += 1
            c1 -= 1
        if c1 == c2:
            print(i + 1)
            break
    else:
        print(-1)