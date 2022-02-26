for _ in range(int(input())):
    n, k = map(int, input().split())
    used = [False] * n
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    flag = True
    while flag:
        flag = False
        for i in range(n):
            if not used[i] and a[i] <= k:
                used[i] = True
                flag = True
                k += b[i]
    print(k)