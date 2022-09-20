s = input()
t = list(s)
ans = []
for i in range(len(s)):
    if s[i] == '4':
        t[i] = '3'
        ans.append('1')
    elif len(ans) != 0:
        ans.append('0')
print(''.join(t), ''.join(ans))