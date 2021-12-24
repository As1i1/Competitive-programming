import random
for _ in range(int(input())):
    n, m = map(int, input().split())
    if n == 1 and m == 1:
        print(0)
    else:
        print(min(m, n, 2))