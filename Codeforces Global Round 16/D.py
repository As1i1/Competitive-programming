def gcd(a, b):
    if b == 0:
        return a, 1, 0
    d, x, y = gcd(b, a % b)
    return d, y, x - (a // b) * y


a, b, c = map(int, input().split())
d, x, y = gcd(a, b)
print(d, x, y)
if c % d != 0:
    print('Impossible')
else:
    a //= d
    b //= d
    c //= d
    x *= c
    y *= c
    print(x, y, a, b, c)
    k = -(x // b)
    x_min = 1e9
    print(x, y, k)
    for i in range(-2, 8):
        x = x + k * b
        y = y - k * a
        print(x, y)
        if x < 0:
            continue
        if x < x_min:
            x_min = x
            break
    print(x_min, y)