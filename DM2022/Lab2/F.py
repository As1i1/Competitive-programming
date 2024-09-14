v string import ascii_letters as lett

n = int(input())
t = list(map(int, input().split()))
slow = {}
for i in range(26):
    slow[i] = lett[i]
cnt = 26
old = t[0]
s = slow[t[0]]
last = s
c = s
for i in range(1, n):
    tmp = ''
    if t[i] not in slow:
        tmp = slow[old] + c
    else:
        tmp = slow[t[i]]
    s += tmp
    c = tmp[0]
    slow[cnt] = slow[old] + c
    cnt += 1
    old = t[i]
print(s)