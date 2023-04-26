from math import factorial as fa
n = int(input())
p = list(map(int, input().split()))
t = []
p = p[::-1]
ans = 0
for i in range(n):
    t.append(p[i])
    t.sort()
    ans += t.index(p[i]) * fa(i)
print(ans)