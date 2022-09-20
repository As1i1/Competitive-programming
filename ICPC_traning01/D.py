n, m = map(int, input().split())
a = set(list(map(int, input().split())))
b = set(list(map(int, input().split())))
ans = True
for elem in a:
    if elem in b:
        ans = False
        break
if ans:
    print('You Win')
else:
    print('You Lose')