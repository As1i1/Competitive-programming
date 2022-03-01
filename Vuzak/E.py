n, k = map(int, input().split())
m = k * (k + 1) // 2
t = n - (n // k) * k
ans = (n // k) * m + (t + 1) * t // 2
print(ans)