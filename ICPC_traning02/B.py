for _ in range(int(input())):
    a = int(input())
    ans = 1
    for i in range(1, a):
        if (i * (i + 1)) // 2 <= a:
            ans = i
    print(ans)