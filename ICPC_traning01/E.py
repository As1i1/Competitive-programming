from math import ceil
f, a, b = map(int, input().split())
if f + a >= 1000:
    print(1)
elif b >= a:
    print(-1)
else:
    x = 1000 - f - a
    print(ceil(x / (a - b)) + 1)