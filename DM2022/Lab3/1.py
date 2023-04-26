n, k = map(int ,input().split())
gre = [str(i) for i in range(k)]
while len(gre[0]) != n:
    gre_ = gre.copy()
    gre = []
    for i in range(k):
        if i % 2 == 0:
            for g in gre_:
                gre.append(str(i) + g)
        else:
            for g in gre_[::-1]:
                gre.append(str(i) + g)
print(*gre, sep='\n')