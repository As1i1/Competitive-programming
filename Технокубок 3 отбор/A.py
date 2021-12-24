for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    ans = 1
    if a[0] == 1:
        ans += 1
    for i in range(1, n):
        if a[i - 1] == 0 and a[i] == 0:
            ans = -1e9
        elif a[i - 1] == 1 and a[i] == 1:
            ans += 5
        elif a[i - 1] == 0 and a[i] == 1:
            ans += 1
    if ans < 0:
        print(-1)
    else:
        print(ans)