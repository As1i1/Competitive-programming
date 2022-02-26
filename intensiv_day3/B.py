def check(a, mid):
    nw = [0] * len(a) # количество новых школьников в i-школе.
    for i in range(len(a) - 1):
        if a[i] + nw[i] > mid:
            d = min(a[i] + nw[i] - mid, a[i])
            nw[i + 1] += d
            a[i] -= d
        else:
            d = min(mid - a[i] - nw[i], a[i + 1])
            a[i + 1] -= d
            nw[i] += d
    for i in range(len(a)):
        if a[i] + nw[i] > mid:
            return False
    return True


n = int(input())
a = list(map(int, input().split()))
l, r = 1, max(a) + 1
while (r - l > 1):
    mid = (r + l) // 2
    if check(a.copy(), mid):
        r = mid
    else:
        l = mid
if check(a, l):
    print(l)
else:
    print(r)