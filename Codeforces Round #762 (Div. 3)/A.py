for _ in range(int(input())):
    s = input()
    if len(s) % 2 == 1 or s[:len(s) // 2] != s[len(s) // 2:]:
        print("NO")
    else:
        print("YES")