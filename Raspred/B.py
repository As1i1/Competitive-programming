h, m = input().split(':')
a, b = map(int, input().split())
if int(m) == 0:
    print(f"{h}:{m}")
elif a >= int(m):
    print(f"{h}:00")
elif int(h) == 23 and b >= 60 - int(m):
    print(f"{h}:59")
elif b >= 60 - int(m):
    print(f"{str(int(h) + 1).rjust(2, '0')}:00")
else:
    print(f"{h}:{str(int(m) + b).rjust(2, '0')}")
