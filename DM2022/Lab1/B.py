def isl(s1):
    global k
    table = []
    val = []
    for j in range(len(s1)):
        s, v = str(bin(j))[2:].rjust(k, '0'), s1[j]
        table.append(s)
        val.append(int(v))

    j = 0
    while True:
        table[j] = [table[j], val[0]]
        if len(val) == 1:
            break
        val1 = [(val[k] + val[k + 1]) % 2 for k in range(len(val) - 1)]
        val = val1
        j += 1

    for j in range(len(table)):
        if table[j][1] == 1 and table[j][0].count('1') > 1:
            return False
    return True



def lt(b1, b2):
    for j in range(len(b1)):
        if b1[j] > b2[j]:
            return False
    return True


def ism(s):
    for x1 in range(len(s)):
        for x2 in range(len(s)):
            b1 = str(bin(x1))[2:].rjust(k, '0')
            b2 = str(bin(x2))[2:].rjust(k, '0')
            if lt(b1, b2):
                if s[x1] > s[x2]:
                    return False
    return True


def iss(s):
    for j in range(len(s) // 2):
        if s[j] == s[len(s) - j - 1]:
            return False
    return True



f1, f0, sss, m, l = [0, 0, 0, 0, 0]
n = int(input())
for i in range(n):
    k, s = input().split()
    k = int(k)
    if k == 0:
        m += 1
        l += 1
        if s == '0':
            f0 += 1
        else:
            f1 += 1
    else:
        if isl(s):
            l += 1
        if s[0] == '0':
            f0 += 1
        if s[-1] == '1':
            f1 += 1
        if iss(s):
            sss += 1
        if ism(s):
            m += 1
#print(f0, f1, sss, m, l)
if f0 == n or f1 == n or sss == n or m == n or l == n:
    print("NO")
else:
    print("YES")