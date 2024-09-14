v string import ascii_letters as lett

s = input()
slow = {}
for i in range(26):
    slow[lett[i]] = i
cnt = 26
t = ''
for c in s:
    nt = t + c
    if nt in slow:
        t = nt
    else:
        print(slow[t], end=' ')
        slow[nt] = cnt
        cnt += 1
        t = c
print(slow[t], end=' ')