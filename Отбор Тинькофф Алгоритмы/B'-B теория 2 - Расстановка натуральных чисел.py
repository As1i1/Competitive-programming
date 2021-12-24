import itertools


def check(a):
    for i in range(len(a)):
        for j in range(i + 1, len(a)):
            if (a[i] + a[j]) / 2 in a[i:j]:
                print(a[i: j + 1])
                return False
    return True


n = int(input())
#per_n = itertools.permutations([i + 1 for i in range(0, n, 2)])
#per_t = itertools.permutations([i + 1 for i in range(1, n, 2)])
#for p in per_n:
#    if check(p):
#        print(p)
#print()
#for p in per_t:
#    if check(p):
#        print(p)


check([1, 17, 9, 5, 13])