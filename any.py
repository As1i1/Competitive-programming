for i in range(int(input())):
    n, l, r = map(int, input().split())
    print((r - 1) // n - (l - 1) // n)