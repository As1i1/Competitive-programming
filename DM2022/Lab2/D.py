import string

s = input()
sp = [string.ascii_lowercase[i] for i in range(26)]
for e in s:
    i = sp.index(e)
    print(i + 1, end=' ')
    sp.pop(i)
    sp = [e] + sp