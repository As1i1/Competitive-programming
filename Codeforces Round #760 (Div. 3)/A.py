for _ in range(int(input())):
    b = list(map(int, input().split()))
    a1 = b[0]
    a2 = b[1]
    a3 = b[2]
    for i in range(2, 7):
        if a1 + a2 + b[i] == b[-1]:
            a3 = b[i]
            break
    print(a1, a2, a3)

