n, c = input().split()
n = int(n)
a = []
mx = 0
t = ''
c1, c2 = map(int, c.split(','))
for i in range(n):
    a.append(input().split())
for i in a:
    d1, d2 = map(int, i[1].split(','))
    mx1 = d1 * 100 + d2
    if d1 <= c1 and d2 <= c2 and mx1 >= mx:
        mx = d1 * 100 + d2
        t = i[0]
if t:
    print(t)
else:
    print(-1)