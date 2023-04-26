from math import factorial as fa

def get(n_, k):
    ans = []
    p = [i for i in range(1, n_ + 1)]
    while n_ != 0:
        t = k // fa(n_ - 1)
        ans.append(p[t])
        p.remove(p[t])
        k -= t * fa(n_ - 1)
        n_ -= 1
    return ans

n = int(input())
p = list(map(int, input().split()))
t = []
p = p[::-1]
ans = 0
for i in range(n):
    t.append(p[i])
    t.sort()
    ans += t.index(p[i]) * fa(i)

k1, k2 = ans - 1, ans + 1
if ans == 0:
    print(' '.join(['0'] * n))
    print(*get(n, k2))
elif ans == fa(n) - 1:
    print(*get(n, k1))
    print(' '.join(['0'] * n))
else:
    print(*get(n, k1))
    print(*get(n, k2))