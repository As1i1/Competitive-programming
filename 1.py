t = int(input())
for i in range(t):
    n, l, r = map(int, input().split())
    if r - l <= n and n == l:
        print(1 if l % n == 0 else 0)
    else:
        print(r // n - l // n if r % n != 0 else (r - l) // n)