for _ in range(int(input())):
    slow_alf = {}
    s = input()
    ans = 0
    t = input()
    for i in range(len(s)):
        slow_alf[s[i]] = i + 1
    for i in range(1, len(t)):
        ans += abs(slow_alf[t[i]] - slow_alf[t[i - 1]])
    print(ans)