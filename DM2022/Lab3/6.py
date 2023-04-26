n = int(input())
ans = []
for i in range(2 ** n):
    flag = False
    for j in range(n):
        if i & (1 << j):
            if flag:
                break
            flag = True
        else:
            flag = False
    else:
       ans.append(bin(i)[2:].rjust(n, '0'))
print(len(ans))
print(*ans, sep='\n')