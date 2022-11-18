n = int(input())
table = []
val = []
for i in range(int(2 ** n)):
    s, v = input().split()
    table.append(s)
    val.append(int(v))

i = 0
while True:
    table[i] = [table[i], val[0]]
    if len(val) == 1:
        break
    val1 = [(val[i] + val[i + 1]) % 2 for i in range(len(val) - 1)]
    val = val1
    i += 1

for i in range(len(table)):
    print(table[i][0], table[i][1])