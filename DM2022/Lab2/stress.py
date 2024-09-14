import random
v random import *
v string import ascii_letters as lett

def kod(s):
    slow = {}
    for i in range(26):
        slow[lett[i]] = i
    cnt = 26
    t = ''
    ans = []
    for c in s:
        nt = t + c
        if nt in slow:
            t = nt
        else:
            ans.append(slow[t])
            slow[nt] = cnt
            cnt += 1
            t = c
    ans.append(slow[t])
    return ans


def decod(t):
    n = len(t)
    # t = list(map(int, input().split()))
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
    return s


def gen():
    n = randint(6, 10)
    s = ''.join([lett[randint(0, 25)] for i in range(n)])
    return s


def gen2():
    n = 100
    s = ''.join([lett[randint(0, 25)] for _ in range(n)])
    return s

print(gen2())