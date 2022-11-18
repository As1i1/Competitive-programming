def getor(x, y):
    return f"(({x}|{x})|({y}|{y}))"


def getand(x, y):
    return f"(({x}|{y})|({x}|{y}))"

def build(t):
    if t == 0:
        return "((A0|B0)|(A0|B0))"
    s1 = build(t - 1)
    x = f"A{t}"
    y = f"B{t}"
    s = f"(({s1}|{getor(x, y)})|({x}|{y}))"
    # if t % 2 == 1:
    #     s = f"({s1}|{getor(x, y)})|({x}|{y})"
    # else:
    #     tmp1 = getor(x, y)
    #     tmp2 = getand(x, y)
    #     s = f"{getor(getand(s1, tmp1), tmp2)}"
    return s

n = int(input())
ans = build(n - 1)
# b = 0
# for i in ans:
#     if i == '(':
#         b += 1
#     elif i == ')':
#         b -= 1
#     print(b)
print(build(n - 1))