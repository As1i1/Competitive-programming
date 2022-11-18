n = int(input())
m = int(1e9 + 7)
if n % 3 == 2:
    print(int(pow(2, n) - pow(2, n // 3 + 1)) % m)
else:
    print(pow(2, n) % m)