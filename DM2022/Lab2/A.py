n = int(input())
n_s = len(str(n))
t = list(map(int, input().split()))
a = []
for i in range(n):
    a.append([t[i], str(i).rjust(n_s, '0')])
a.sort(key=lambda x: -x[0])
slow = {}
while len(a) != 1:
    a1 = a.pop()
    a2 = a.pop()
    for e in range(0, len(a1[1]), n_s):
        slow[a1[1][e:e + n_s]] = '1' + slow.get(a1[1][e:e + n_s], '')
    for e in range(0, len(a2[1]), n_s):
        slow[a2[1][e:e + n_s]] = '0' + slow.get(a2[1][e:e + n_s], '')
    a.append([a1[0] + a2[0], a1[1] + a2[1]])
    a.sort(key=lambda x: -x[0])
ans = 0
for val, key in slow.items():
    ans += len(key) * t[int(val)]
print(ans)