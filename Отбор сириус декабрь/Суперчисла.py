a, b = map(int, input().split())
prime = []
numbers = [False for i in range(b + 1)]
for i in range(2, b + 1):
    if not numbers[i]:
        prime.append(i)
        for j in range(2 * i, b + 1, i):
            numbers[j] = True
ans = set()
for x in prime:
    for y in prime:
        if a <= x + y <= b:
            ans.add(x + y)
ans = sorted(list(ans))
for i in ans:
    print(i)
