def impl(x, y):
    return not x or y


def f(y1, y2, y3):
    return impl(impl(y1, impl(y2, y3)), impl(y1 and y2, y3))

def g(y1, y2, y3):
    return impl(impl(y1 and y2, y3), impl(x1, impl(x2, x3)))


for x1 in [False, True]:
    for x2 in [False, True]:
        for x3 in [False, True]:
            print(x1, x2, x3, f(x1, x2, x3))

print('\n\n\n')

for x1 in [False, True]:
    for x2 in [False, True]:
        for x3 in [False, True]:
            print(x1, x2, x3, g(x1, x2, x3))