n = int(input())
a = list(map(int, input().split()))
a.sort()
if n == 1:
    print(a[0])
elif n == 2:
    print((a[0] + a[1]) / 2)
else:
    print(min(a[1], (a[0] + a[-1]) / 2))