for _ in range(int(input())):
    l, r = map(int, input().split())
    cnt = [0 for i in range(20)]
    i = 1
    while i < r:
        cnt[i] +=
    for i in range(20):

    n = r - l + 1
    ans = n - 1
    for i in range(20):
        ans = min(ans, n - cnt[i])
    print(ans)