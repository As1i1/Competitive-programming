n = int(input())
a = []
for i in range(n):
    s, a1 = map(int, input().split())
    a.append([a1 / s, i])
a.sort(key=lambda x: x[0])
print(f"1\n{a[0][1] + 1}\n1\n{a[-1][1] + 1}")