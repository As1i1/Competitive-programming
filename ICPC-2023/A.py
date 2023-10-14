n = int(input())
k = int(input())
s1 = int(input())
s2 = int(input())

mn = n
mx = k * n


def check(s):
    return mn <= s <= mx


if not check(s1) and not check(s2):
    print("Equal")
elif not check(s1):
    print("Second")
elif not check(s2):
    print("First")
else:
    if n == 1:
        print("Equal")
    elif s1 == s2 or s1 == n * (k + 1) - s2:
        print("Equal")
    elif (s1 < s2 < n * (k + 1) - s1) or (s1 > s2 > n * (k + 1) - s1):
        print("Second")
    else:
        print("First")
