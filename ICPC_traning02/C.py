n = int(input())
a = list(map(int, input().split()))
a.sort()
while True:
    cnt = 0
    for i in range(n):
        if a[i] > 0:
            a[i] -= 1
        if a[i] == 0:
            cnt += 1
    if (cnt == n - 1 and sum(a) == 1) or (cnt == n):
        print('YES')
        break
    elif cnt == n - 1 and sum(a) != 1:
        print('NO')
        break