def check(s, a):
    if s == "a" and a == "a":
        return "YES"
    elif len(s) == 1 and s != "a":
        return "NO"
    else:
        if s[0] == a:
            return check(s[1:], chr(ord(a) - 1))
        elif s[-1] == a:
            return check(s[:-1], chr(ord(a) - 1))
        else:
            return "NO"


for _ in range(int(input())):
    s = input()
    print(check(s, chr(max(ord(s[0]), ord(s[-1])))))