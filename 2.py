l, r = map(float, input().split())


mn_p = []
for q in range(1, 13):
    cur_mn = 1e9
    for p in range(1, int(2 ** q)):
        t = p / (2 ** q)
        if l <= t < r:
            cur_mn = min(p, cur_mn)
    mn_p.append(cur_mn)
print(mn_p)