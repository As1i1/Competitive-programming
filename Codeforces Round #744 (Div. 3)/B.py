for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    last = a[0]
    ans = 0
    ans_t = []
    for i in range(1, n):
        if a[i] < last:
            r = i + 1
            l = 0
            for j in range(i):
                if a[j] > a[i]:
                    l = j
                    break
            a[l:r] = sorted(a[l:r])
            ans += 1
            ans_t.append([l + 1, r, r - l - 1])
        last = a[i]
    print(ans)
    for i in range(ans):
        print(*ans_t[i])