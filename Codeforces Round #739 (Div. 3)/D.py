a = [str(2 ** i) for i in range(0, 100)]
for _ in range(int(input())):
    s = input()
    ans = 1e9
    for number in a:
        k1, k2 = 0, 0
        d = 0
        while k1 < len(number) and k2 < len(s):
            if number[k1] != s[k2]:
                k2 += 1
                d += 1
            else:
                k1 += 1
                k2 += 1
        ans = min(ans, d + len(number) - k1 + len(s) - k2)
    print(ans)