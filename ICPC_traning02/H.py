n = int(input())
a = list(map(int, input().split()))
flag = True
for i in range(n):
    if a[i] > i + 1:
        flag = False
if not flag:
    print('NO')
else:
    print("YES")
    ans = []
    while len(a) != 0:
        tmp = 0
        for i in range(len(a)):
            if a[i] == i + 1:
                tmp = a[i]
        a.pop(tmp - 1)
        ans.append(tmp)
    print(*ans[::-1])