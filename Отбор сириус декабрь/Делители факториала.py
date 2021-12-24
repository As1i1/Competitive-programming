facts = {}


def fact(n):
    i = 2
    while i * i <= n:
        while n % i == 0:
            facts[i] = facts.get(i, 0) + 1
            n //= i
        i += 1
    if n != 1:
        facts[n] = facts.get(n, 0) + 1


n = int(input())
if n == 1:
    print(1)
else:
    ans = 1
    for i in range(2, n + 1):
        fact(i)
    for val in facts.values():
        ans *= (val + 1)
    print(ans)