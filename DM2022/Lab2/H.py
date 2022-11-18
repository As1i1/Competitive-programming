from string import ascii_letters as le
from math import *
from fractions import *

n = int(input())
cnt = list(map(int, input().split()))
ln = sum(cnt)
tmp = input()
d = Fraction(int(tmp, 2), 2 ** len(tmp))

l, r = Fraction(0, 1), Fraction(1, 1)
ans = ''
for k in range(ln):
    lnt = r - l
    for i in range(1, n):
        nl = l + Fraction(sum(cnt[:i]), ln) * lnt
        nr = l + Fraction(sum(cnt[:i + 1]), ln) * lnt
        if nl <= d <= nr:
            l = nl
            r = nr
            ans += le[i]
            break
    if len(ans) != k + 1:
        r = l + Fraction(sum(cnt[:1]), ln) * lnt
        ans += le[0]
print(ans)
