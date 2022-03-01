a = int(input())
b = int(input())
x = int(input())
y = int(input())
if a >= x or b >= x:
    print(1)
    exit(0)
if b >= a:
    print((x + b - 1) // b)
else:
    if x <= y * a:
        print((x + a - 1) // a)
    else:
        ans = y
        x -= y * a
        print(ans + (x + b - 1) // b)