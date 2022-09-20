a = list(map(int, input().split()))
d = {}
for i in range(len(a)):
    if a[i] in d:
        d[a[i]] += d.get(a[i], 0)
    else:
        d[a[i]] = 1
for key, val in d.items():
    if val == 1:
        print(key)