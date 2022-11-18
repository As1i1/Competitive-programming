s = input()
t = [s[i] for i in range(len(s))]
t.sort()
while len(t[0]) != len(s):
    for i in range(len(s)):
        t[i] = s[i] + t[i]
    t.sort()
print(t[0])