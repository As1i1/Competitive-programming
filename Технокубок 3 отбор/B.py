for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    mx = max(a)
    ans = 0
    i = n - 1
    while i > -1:
        if a[i] < mx:
            ans += 1
            tmp = a[i]
            i -= 1
            while i > -1 and a[i] <= tmp:
                i -= 1
        else:
            break
    print(ans)
