n, k = map(int, input().split())
k1, k2 = 0, n
for i in range(k):
    a, b = map(int, input().split())
    k1 = max(k1, a)
    k2 = min(k2, b)
print(max(0, k2 - k1 + 1))