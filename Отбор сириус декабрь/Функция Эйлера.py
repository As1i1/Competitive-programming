n = int(input())
i = 2
res = n
while i * i <= n:
    if n % i == 0:
        res -= (res // i)
        while n % i == 0:
            n //= i
    i += 1
if n != 1:
    res -= (res // n)
print(res)