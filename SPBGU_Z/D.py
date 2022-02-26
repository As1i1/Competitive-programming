n = int(input())
p = 1
for i in range(1, n + 2):
    p *= i
t = []
MOD = 998244353
while p >= MOD:
    t.append(p % MOD)
    p //= MOD
t.append(p)
cnt = 0
i = 0
while t[i] == 0:
    cnt += 1
    i += 1
print(cnt, t[i])