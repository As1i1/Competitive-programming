for _ in range(int(input())):
    s = input()
    cur = ""
    last = ""
    order = [s[-1]]
    i = len(s) - 1
    st = set()
    tmp_s = ""
    while i > -1:
        if s[i] in st:
            cur = s[i] + cur
        else:
            if tmp_s == "" or tmp_s == s[i]:
                tmp_s = s[i]
            else:
                pass
