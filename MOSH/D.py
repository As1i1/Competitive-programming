f = open('d2.txt', 'r', encoding='utf-8').readlines()
a = []
b = []
i = 1
while i != len(f):
    n, m = map(int, f[i].strip().split())
    k = 0
    i += 1
    tmp = []
    while k != m + 1:
        tmp.append(f[i + k].strip())
        k += 1
    i += k
    a.append(tmp)
    b.append([n, m])
for i in range(len(a)):
    print(b[i][0], b[i][1])
    for j in range(len(a[i])):
        print(a[i][j])
        a[i][j] = list(map(int, a[i][j].split()))
    print(flush=True)
    s = input()
    if s == 'NO':
        sm = sum([a[i][j][0] for j in range(len(a[i]))])
        print(sm)
        print('1 ' * b[i][1])
