m, s = map(int, input().split())
if m == 1 and s == 0:
    print(0, 0)
    exit(0)
mx = mn = '1' + '0' * (m - 1)
mx = list(map(int, list(mx)))
mn = list(map(int, list(mn)))
new_s = s - 1
i = 0
while new_s and i < m:
    if mx[i] == 9:
        i += 1
    else:
        mx[i] += 1
        new_s -= 1
if new_s != 0:
    print('-1 -1')
    exit(0)
new_s = s - 1
i = m - 1
while new_s and i > -1:
    if mn[i] == 9:
        i -= 1
    else:
        mn[i] += 1
        new_s -= 1
if new_s != 0:
    print('-1 -1')
    exit(0)
print(''.join(map(str, mn)), ''.join(map(str, mx)))