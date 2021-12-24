for _ in range(int(input())):
    a, b = map(int, input().split())
    print(b % max(b // 2 + 1, a))