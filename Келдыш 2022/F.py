from math import factorial
ans = 0
for i in range(1, 11):
    ans += factorial(10) // factorial(10 - i)
print(ans)