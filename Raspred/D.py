s = input().split()
slow = {}
for i in s:
    if i[0] == '#' and i.count('#') == 1 and len(i) >= 2:
        slow[i] = slow.get(i, 0) + 1
print(len(slow.items()))
for (k, v) in slow.items():
    print(k, v)
