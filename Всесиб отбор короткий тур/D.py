import random
a = []
for i in range(6):
    a.append(int(input()))
k = int(input())
k1 = k
print("!", end=" ")
for i in range(6):
    x = (k1 // 6 + random.randint(0, k) * random.choice([-1, 1])) // 2
    a[i] += k1 // 6 + x
    k -= x
    print(a[i], end=" ")