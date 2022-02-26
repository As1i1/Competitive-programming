n = int(input())
k = list(map(int, input().split()))
k1 = n - 1

while sum(k) != 0:
    print('Flip and wait', flush=True)
    while k1 >= 0 and k[k1] == 0:
        k1 -= 1
    cnt = 0
    while True:
        b = input()
        if b == 'Tired' or b == 'Fail' or b == 'Burn':
            exit(0)
        for i in range(1, len(b) - 2, 2):
            cnt += 1
        if cnt < k1 + 1:
            print('Wait', flush=True)
        else:
            break
    k[k1] -= 1
print('Stop', flush=True)