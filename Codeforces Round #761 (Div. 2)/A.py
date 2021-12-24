for _ in range(int(input())):
    s = list(input())
    t = input()
    b, c = t.find('b'), t.find('c')
    s.sort()
    if t[0] != 'a' or c < b or 'a' not in s or 'b' not in s or 'c' not in s:
        print(''.join(s))
    else:
        for i in range(len(s)):
            if s[i] == 'b':
                for j in range(i + 1, len(s)):
                    if s[j] == 'c':
                        s[i] = 'c'
                        s[j] = 'b'
                        break
        print(''.join(s))

