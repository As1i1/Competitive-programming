for _ in range(int(input())):
    n = int(input())
    s1 = input()
    s2 = input()
    a = []
    cnt2, cnt1 = 0, 0
    for i in range(n):
        if s1[i] == s2[i] and s1[i] == '1':
            a.append(0)
        elif s1[i] == s2[i] and s1[i] == '0':
            a.append(1)
            cnt1 += 1
        else:
            a.append(2)
            cnt2 += 1
    cnt = 0
    lst = a[0]
    for i in range(1, n):
        if lst == 0 and a[i] == 1:
            cnt += 1
            i += 1
            if i < n:
                lst = a[i]
        elif lst == 1 and a[i] == 0:
            cnt += 1
            i += 1
            if i < n:
                lst = a[i]
        else:
            lst = a[i]
    print(2 * cnt2 + 2 * cnt + cnt1 - cnt)

    # k1, k2 = 0, 0
    # lst1, lst2 = s1[0], s2[0]
    # while k1 < n and k2 < n:
    #     if