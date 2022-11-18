def kod(s):
    n_s = []
    step2 = 1
    i = 1
    while i != len(s) + 1:
        if step2 == len(n_s) + 1:
            n_s.append('0')
            step2 *= 2
        else:
            n_s += s[i - 1]
            i += 1
    step2 = 1
    k = 0
    while step2 < len(n_s):
        res = 0
        for j in range(len(n_s)):
            if (j + 1) & (1 << k):
                res = res ^ int(n_s[j])
        n_s[step2 - 1] = str(res)
        step2 *= 2
        k += 1
    return ''.join(n_s)


def find(s):
    s = list(input())
    s_e = set()
    step2 = 1
    k = 0
    cnt, ttt = 0, 0
    while step2 < len(s):
        res = 0
        tmp = set()
        for j in range(len(s)):
            if (j + 1) & (1 << k) and j + 1 != step2:
                res = res ^ int(s[j])
                tmp.add(j)
        if s[step2 - 1] != str(res):
            cnt += 1
            ttt = step2 - 1
            if len(s_e) == 0:
                s_e = tmp
            else:
                s_e = s_e.intersection(tmp)
        elif len(s_e) != 0:
            s_e = s_e.difference(tmp)
        step2 *= 2
        k += 1
    if cnt == 1:
        s[ttt] = str(1 - int(s[ttt]))
    else:
        k = s_e.pop()
        s[k] = str(1 - int(s[k]))
    return ''.join(s)



while True:
