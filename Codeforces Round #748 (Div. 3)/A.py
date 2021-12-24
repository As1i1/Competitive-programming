for _ in range(int(input())):
    a, b, c = map(int, input().split())
    mx = max([a, b, c])
    if [a, b, c].count(mx) > 1:
        print(mx - a + 1, mx - b + 1, mx - c + 1)
    else:
        if a == mx:
            print(0, end=" ")
        else:
            print(mx - a + 1, end=" ")
        if b == mx:
            print(0, end=" ")
        else:
            print(mx - b + 1, end=" ")
        if c == mx:
            print(0, end=" ")
        else:
            print(mx - c + 1, end=" ")
        print()