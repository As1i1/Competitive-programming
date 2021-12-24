cnt2, i = 0, 2
old_n = n = int(input())
nt = []
while i * i <= n:
    while n % i == 0:
        if i == 2:
            cnt2 += 1
        else:
            nt.append(i)
        n //= i
    i += 1
if n != 1:
    if n == 2:
        cnt2 += 1
    else:
        nt.append(n)
if cnt2 == 1:
    print('prime')
elif cnt2 >= 2:
    if len(nt) <= 1:
        print('single')
        if len(nt) == 1:
            print(2 * nt[0], end=' ')
            for i in range(1, cnt2):
                print(2, end=' ')
        else:
            for i in range(cnt2):
                print(2, end=' ')
    else:
        print('many')
        print(2 * nt[0] * nt[1], end=' ')
        second = 2
        for i in range(2, len(nt)):
            second *= nt[i]
        print(second, end=' ')
        for i in range(2, cnt2):
            print(2, end=' ')
        print()
        print(2 * nt[0], second * nt[1], end=' ')
        for i in range(2, cnt2):
            print(2, end=' ')
