f = open('muggers.in', 'r').readlines()
fo = open('muggers.out', 'w')
n, k = map(int, f[0].split())
a = list(map(int, f[1].split()))
dp = [0] * (n + 1)
dp[0] = 0
for i in range(1, n + 1):
    mn = 1e9
    for j in range(i - 1, max(-1, i - k - 2), -1):
        mn = min(mn, dp[j])
    dp[i] = mn + a[i - 1]
fo.write(str(dp[-1]))
fo.close()