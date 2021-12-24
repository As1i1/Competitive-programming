for _ in range(int(input())):
    n = int(input())
    s = input()
    if '0' not in s:
        print(1, n - 1, 2, n)
    else:
        ans = False
        for i in range(n // 2, n):
            if s[i] == '0' and not ans:
                print(1, i + 1, 1, i)
                ans = True
        for i in range(n // 2):
            if s[i] == '0' and not ans:
                print(i + 2, n, i + 1, n)
                ans = True