def check(s1, s2, slow):
    a = 0
    if len(s1) > len(s2):
        a += 2
    for i in range(len(s2)):
        if s1[i] != s2[i]:
            a += slow[int(s1[i])]
    return a


def slowly(k):
    slow = {1: 4, 2: 5, 3: 2, 4: 3, 5: 3, 6: 1, 7: 5, 8: 4, 9: 1, 0: 2}
    cur = 0
    ans = 0
    for i in range(int(k)):
        cur += 1
        n_cur, o_cur = str(cur)[::-1], str(cur - 1)[::-1]
        ans += check(n_cur, o_cur, slow)
    return ans


def fast(k):
    k = k[::-1]
    slow = {1: 4, 2: 5, 3: 2, 4: 3, 5: 3, 6: 1, 7: 5, 8: 4, 9: 1, 0: 2}
    ans = 0
    add = 0
    last = 0
    for i in range(len(k)):
        for j in range(1, 11):
            if k[i] == str(j - 1):
                ans += last
            if j == 10:
                last += add + slow[0]
            else:
                last += add + slow[j]
        add = last
        last = 0
    return ans - (len(k) - 1) * 2


for _ in range(int(input())):
    k = input()
    print( fast(k))