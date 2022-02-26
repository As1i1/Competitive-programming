def check(a):
    for i in range(2, len(a)):
        if a[i - 1] + a[i - 2] == a[i]:
            return False
    return True


for _ in range(int(input())):
    n = int(input())
    ans = []
    k1, k2 = 1, n
    if n % 2 == 1:
        k2 -= 1
    while k1 < k2:
        ans.append(k2)
        ans.append(k1)
        k1 += 1
        k2 -= 1
    if n % 2 == 1:
        for i in range(n - 1):
            t = [n] + ans[i:] + ans[:i]
            print(*t)
        print(ans[0], n, *ans[1:])
    else:
        for i in range(n):
            t = ans[i:] + ans[:i]
            print(*t)