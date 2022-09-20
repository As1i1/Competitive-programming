n, k = map(int, input().split())
a1 = list(map(int, input().split()))
a2 = []
sz = 10 ** 5 + 10
suf = [0] * sz
k1 = n - 1
for i in range(sz - 2, -1, -1):
    while k1 >= 0 and a1[k1] == i:
        suf[i] += 1
        k1 -= 1
    suf[i] += suf[i + 1]
for i in range(1, max(a1) + 1):
    a2.append(suf[i])
a2.reverse()
if k % 2 == 0:
    print(*a1)
else:
    print(*a2)