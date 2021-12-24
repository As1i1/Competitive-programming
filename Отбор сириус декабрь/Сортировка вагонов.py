n = int(input())
a = list(map(int, input().split()))
st = []
cur = 1
k1 = 0
ans = []
while True:
    cnt = 0
    while (len(st) == 0 or st[-1] != cur) and k1 < n:
        st.append(a[k1])
        k1 += 1
        cnt += 1
    if cnt:
        ans.append(f'1 {cnt}')
    if len(st) != 0 and st[-1] == cur:
        st.pop()
        cur += 1
        ans.append('2 1')
    elif (len(st) == 0 and cnt == 0) or (st[-1] != cur and cnt == 0):
        break
if cur == n + 1:
    print('\n'.join(ans))
else:
    print(0)