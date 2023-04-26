a = [
    [[2, -1, -3], [8, -7, -6], [-3, 4, 2]],
    [[2, 0, 5], [4, -1, -2], [4, 3, 7]],
    [[5, 3, -7], [-1, 6, -3], [2, -4, 1]]
]

c = [
    [[1, 3, -4], [7, 3, -1], [-1, 5, 2]],
    [[0, 2, -1], [2, 4, 0], [-3, 3, 7]],
    [[5, -2, 5], [3, 2, 1], [-2, 1, 1]]
]

n = 3
perm = [2, 3, 1]

b = [[[0] * n for _ in range(n)] for _ in range(n)]
for j3 in range(n):
    for j1 in range(n):
        for j2 in range(n):
            g1 = eval(f"j{perm[0]}")
            g2 = eval(f"j{perm[1]}")
            g3 = eval(f"j{perm[2]}")
            b[j3][j1][j2] = a[g3][g1][g2]

for slc in b:
    for l in slc:
        print(l)
    print('--------')