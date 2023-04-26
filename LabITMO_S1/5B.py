n, m = map(int, input().split())
a, dp, d = [list(map(int, input().split())) for i in range(n)],  [[0] * m for i in range(n)], [[False] * m for _ in range(n)]
d[0][0] = True
for i in range(n):
    for j in range(m):
        dp[i][j] += a[i][j]
        if i + 1 < n and j + 2 < m:
            dp[i + 1][j + 2] = max(dp[i][j], dp[i + 1][j + 2])
            d[i + 1][j + 2] = d[i + 1][j + 2] | d[i][j]
        if i + 2 < n and j + 1 < m:
            dp[i + 2][j + 1] = max(dp[i][j], dp[i + 2][j + 1])
            d[i + 2][j + 1] = d[i + 2][j + 1] | d[i][j]
if not d[-1][-1]:
    print(-1)
else:
    print(dp[-1][-1])
print(*d, sep='\n')