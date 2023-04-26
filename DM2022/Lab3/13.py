from math import factorial as fa

n, k = map(int, input().split())
p = [i for i in range(1, n + 1)]
while n != 0:
    t = k // fa(n - 1)
    print(p[t], end=' ')
    p.remove(p[t])
    k -= t * fa(n - 1)
    n -= 1
