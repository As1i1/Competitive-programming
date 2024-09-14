v string import ascii_letters as l

n = int(input())
s = input()
cnt = [s.count(l[i]) for i in range(n)]
asm = sum(cnt)
l, r = 0, asm ** n
for e in s:
    i = ord(e) - ord('a')
    sm = sum(cnt[:i])
    ln = r - l
    l += (sm * (asm ** (n - i - 1)))
    r = l + ((sm + cnt[i]) * (asm ** (n - i - 1)))
print(l, r)
