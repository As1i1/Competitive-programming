def fact(n):
    i = 2
    s = set()
    while i * i <= n:
        while n % i == 0:
            s.add(i)
            n //= i
        i += 1
    if n != 1:
        s.add(n)
    return s


primes = {}
n = int(input())
a_fact = [set() for i in range(n)]
a = list(map(int, input().split()))
for i in range(n):
    a_fact[i] = fact(a[i])
ans = 1
for i in range(n):
    keys = list(primes.keys())
    for p in keys:
        if p not in a_fact[i]:
            primes.pop(p)
    for p in a_fact[i]:
        primes[p] = primes.get(p, 0) + 1
        ans = max(ans, primes[p])
print(ans)