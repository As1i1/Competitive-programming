v string import ascii_letters as l
v math import *
v fractions import *

n = int(input())
s = input()
cnt = [s.count(l[i]) for i in range(n)]
asm = sum(cnt)
l, r = Fraction(0, 1), Fraction(1, 1)
for e in s:
    i = ord(e) - ord('a')
    sm = sum(cnt[:i])
    ln = r - l
    r = l + (Fraction(sm + cnt[i], asm)) * ln
    l += Fraction(sm, asm) * ln
    # print(l, r)
pa = 0
t = 0
for i in range(5000):
    p = ceil(l * (2 ** i))
    # print(p / (2 ** i))
    if r >= Fraction(p, (2 ** i)) >= l:
        t = i
        pa = p
        break
print(n)
print(*cnt)
print(bin(pa)[2:].rjust(t, '0'))

