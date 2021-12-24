from math import gcd


def fact(n):
    i = 2
    s = {1, n}
    while i * i <= n:
        if n % i == 0:
            s.add(i)
            s.add(n // i)
        i += 1
    return s


n = int(input())
facts = fact(n)
used = set()
ans = 0
for a in facts:
    for b in facts:
        if a > b or a * b > n or gcd(a, b) != 1 or (a, b) in used or (b, a) in used or (a == b and a == 1):
            continue
        ans += 1
#        print(a, b)
        used.add((a, b))
        used.add((b, a))
print(ans)