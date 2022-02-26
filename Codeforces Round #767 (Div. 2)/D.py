from string import ascii_lowercase
for _ in range(int(input())):
    n = int(input())
    cnt = {}
    a = []
    ans = False
    for i in range(n):
        a.append(input())
        cnt[a[-1]] = cnt.get(a[-1], 0) + 1
        if a[i] == a[i][::-1]:
            ans = True
        elif len(a[i]) == 2:
            if cnt.get(a[i][::-1], 0) != 0:
                ans = True
            for x in ascii_lowercase:
                if cnt.get(a[i][::-1] + x, 0) != 0:
                    ans = True
        else:
            if cnt.get(a[i][::-1], 0) != 0 or cnt.get(a[i][1:3][::-1], 0) != 0:
                ans = True
    print("YES" if ans else "NO")