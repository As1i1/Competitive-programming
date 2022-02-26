for _ in range(int(input())):
    n = int(input())
    s = sum(map(int, input().split()))
    print(0 if s % n == 0 else 1)