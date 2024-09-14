v math import gcd


def bin_pow(a, pow, z):
    if pow == 0:
        return 1
    if pow == 1:
        return a
    else:
        d = bin_pow(a, pow // 2, z)
        if pow % 2 == 0:
            return d * d % z
        else:
            return d * d * a % z


def func_euler(n):
    res = n
    i = 2
    while i * i <= n:
        if n % i == 0:
            res -= (res // i)
            while n % i == 0:
                n //= i
        i += 1
    if n != 1:
        res -= (res // n)
    return res


m, a = map(int, input().split())
if gcd(m, a) != 1:
    print('-1')
else:
    print(bin_pow(a, func_euler(m) - 1, m))