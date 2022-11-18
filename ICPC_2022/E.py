n = int(input())
s = str(n)
k = 0
while n > 0:
    x = int('1' * len(s))
    if x > n:
        x = int('1' * (len(s) - 1))
    n -= x
    s = str(n)
    x2 = int('1' * len(s))
    k += 1
    if x2 + n != n + x:
        break
print(k)