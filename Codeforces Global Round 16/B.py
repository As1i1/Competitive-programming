for _ in range(int(input())):
    s = input()
    if '0' not in s:
        print(0)
    else:
        cnt = 0
        lst = s[0]
        for i in range(1, len(s)):
            if s[i] == '1' and lst == '0':
                cnt += 1
            lst = s[i]
        if lst == '0':
            cnt += 1
        if cnt == 1:
            print(1)
        else:
            print(2)