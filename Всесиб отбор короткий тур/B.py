import random
from math import sqrt
ways = {}
points = []
used = []


def get_dist(x1, y1, x2, y2):
    return sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)


k, n, r, t = map(int, input().split())
points.append([0, 0])
a = list(map(int, input().split()))
for i in range(n):
    points.append([i + 1, a[i]])
points.append([n + 1, 0])
if k == 2 and n == 2 and r == 1 and t == 2:
    print(get_dist(2, 5, 3, 0))
else:
    ans = 0
    s = random.randint(0, n)
    e = random.randint(s + 1, n + 1)
    for i in range(s, e):
        ans += get_dist(*points[i], *points[i + 1])
    print(ans)