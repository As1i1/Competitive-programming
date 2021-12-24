for _ in range(int(input())):
    s = input()
    ans1 = ''
    cnt0 = 0
    for i in range(len(s) - 1, -1, -1):
        if s[i] == '0':
            cnt0 += 1
        if cnt0 == 2:
            ans1 = str(int(s[:i + 1] + '0'))
            break
    ans2 = ''
    cnt2, cnt5 = 0, 0
    for i in range(len(s) - 1, -1, -1):
        if s[i] == '5':
            cnt5 += 1
        if s[i] == '2' and cnt5 >= 1:
            cnt2 += 1
        if cnt2 >= 1:
            ans2 = str(int(s[:i + 1] + '5'))
            break
    ans3 = ''
    cnt5, cnt0 = 0, 0
    for i in range(len(s) - 1, -1, -1):
        if s[i] == '0':
            cnt0 += 1
        if s[i] == '5' and cnt0 >= 1:
            cnt5 += 1
        if cnt5 >= 1:
            ans3 = str(int(s[:i + 1] + '0'))
            break
    ans4 = ''
    cnt7, cnt5 = 0, 0
    for i in range(len(s) - 1, -1, -1):
        if s[i] == '5':
            cnt5 += 1
        if s[i] == '7' and cnt5 >= 1:
            cnt7 += 1
        if cnt7 >= 1:
            ans4 = str(int(s[:i + 1] + '5'))
            break
    print(min(len(s) - len(ans1), len(s) - len(ans2), len(s) - len(ans3), len(s) - len(ans4)))