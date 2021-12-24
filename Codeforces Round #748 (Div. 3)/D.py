def check(s, k, x):
    for elem in s:
        if (elem - x) % k != 0:
            return False
    return True


for _ in range(int(input())):
    n = int(input())
    s = set(map(int, input().split()))
    mn = min(s)
    ans = 1
    if len(s) == 1:
        print(-1)
        continue
    s.remove(mn)
    for i in range(2, min(s) - mn + 1):
        if check(s, i, mn):
            ans = max(ans, i)
    print(ans)