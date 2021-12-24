for _ in range(int(input())):
    a, s = input().split()
    k1 = len(s) - 1
    k2 = len(a) - 1
    b = []
    flag = True
    while k1 >= 0:
        if k2 < 0:
            b.append(s[k1])
            k1 -= 1
        else:
            if s[k1] >= a[k2]:
                b.append(str(int(s[k1]) - int(a[k2])))
                k1 -= 1
                k2 -= 1
            else:
                if k1 == 0 or int(s[k1 - 1:k1 + 1]) - int(a[k2]) > 9 or int(s[k1 - 1:k1 + 1]) - int(a[k2]) < 0:
                    flag = False
                    break
                else:
                    b.append(str(int(s[k1 - 1:k1 + 1]) - int(a[k2])))
                    k1 -= 2
                    k2 -= 1
    while b and b[-1] == "0":
        b.pop()
    if flag and k2 == -1:
        if not b:
            print(0)
        else:
            print(''.join(b[::-1]))
    else:
        print(-1)