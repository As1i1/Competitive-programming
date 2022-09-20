n = int(input())
a = list(map(int, input().split()))
a.sort()
cnt = 1
ans = 0
k1, k2 = 0, n - 1
while k1 <= k2:
    if a[k1] <= cnt:
        cnt += 1
        k1 += 1
    else:
        cnt += 1
        ans += 1
        k2 -= 1
print(ans)

