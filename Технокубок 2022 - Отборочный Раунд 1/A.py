def is_prime(n):
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True


for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    sm = sum(a)
    cnt_n = 0
    ans = []
    ans_n = []
    for i in range(n):
        if a[i] % 2 == 0:
            ans.append(i + 1)
        else:
            cnt_n += 1
            ans_n.append(i + 1)
    if cnt_n % 2 == 0 or not is_prime(sm):
        print(n)
        print(*(ans + ans_n))
    else:
        print(n - 1)
        print(*(ans + ans_n[1:]))
