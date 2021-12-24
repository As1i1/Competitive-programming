from math import log10
for _ in range(int(input())):
    x1, p1 = map(int, input().split())
    x2, p2 = map(int, input().split())
    p1 += int(log10(x1))
    p2 += int(log10(x2))
    if p1 > p2:
        print(">")
    elif p1 < p2:
        print("<")
    else:
        s1, s2 = str(x1), str(x2)
        while len(s1) != len(s2):
            if len(s1) < len(s2):
                s1 += "0"
            else:
                s2 += "0"
        k1, k2 = 0, 0
        flag = True
        while k1 < len(s1) and k2 < len(s2):
            if s1[k1] == s2[k2]:
                k1 += 1
                k2 += 1
            elif s1[k1] < s2[k2]:
                print("<")
                flag = False
                break
            else:
                print(">")
                flag = False
                break
        if flag:
            print("=")