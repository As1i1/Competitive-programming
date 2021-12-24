ans = []
i = 1
while len(ans) < 1000:
    if i % 10 != 3 and i % 3 != 0:
        ans.append(i)
    i += 1
for _ in range(int(input())):
    k = int(input())
    print(ans[k - 1])