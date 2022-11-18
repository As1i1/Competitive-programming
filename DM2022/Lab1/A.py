n = int(input())

f1 = [list(map(int, input().split())) for _ in range(n)]
f2 = [list(map(int, input().split())) for _ in range(n)]


def ref(f):
    for i in range(n):
        if f[i][i] == 0:
            return 0
    return 1


def a_ref(f):
    for i in range(n):
        if f[i][i] == 1:
            return 0
    return 1


def sim(f):
    for i in range(n):
        for j in range(n):
            if f[i][j] != f[j][i]:
                return 0
    return 1


def a_sim(f):
    for i in range(n):
        for j in range(n):
            if i != j and f[i][j] == 1 and f[j][i] == 1:
                return 0
    return 1


def tran(f):
    for i in range(n):
        for j in range(n):
            if f[i][j] == 1:
                for k in range(n):
                    if f[j][k] == 1:
                        if f[i][k] == 0:
                            return 0
    return 1



print(ref(f1), a_ref(f1), sim(f1), a_sim(f1), tran(f1))
print(ref(f2), a_ref(f2), sim(f2), a_sim(f2), tran(f2))

f3 = [[0 for _ in range(n)] for _ in range(n)]

for i in range(n):
    for k in range(n):
        for y in range(n):
            if f1[i][y] == 1 and f2[y][k] == 1:
                f3[i][k] = 1
        print(f3[i][k], end=' ')
    print()