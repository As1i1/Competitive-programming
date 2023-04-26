from math import gcd
g, l = map(int, input().split())

ans, i = 0, 1
n = g * l

while i * i <= l:
    if l % i == 0:
        f = i
        s = n // i
        if gcd(f, s) == g:
            ans += 1

        if i != n // i:

            f = l // i
            s = n // f
            if gcd(f, s) == g:
                ans += 1
    i += 1


print(ans)