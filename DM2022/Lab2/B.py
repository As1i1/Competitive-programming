s = input()
t = []
for i in range(len(s)):
    t.append(s[i:] + s[:i])
t.sort()
for i in range(len(t)):
    print(t[i][-1], end='')