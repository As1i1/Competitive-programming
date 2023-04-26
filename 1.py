import re
import itertools


def check(w):
    if w.count("a") >= 2 and w.count("b") >= 1:
        return True
    return False



r = re.compile(r'^c*(ac*a(a|c)*b|ac*b(b|c)*a|b(c|b)*a(c|b)*a)(c|b|a)*$')

alphabet = 'abc'
K = 11

for n in range(K):
    print(f'n={n}: ', end='')
    for w in itertools.product(alphabet, repeat=n):
        sw = ''.join(w)
        if bool(re.fullmatch(r, sw)) != check(sw):
            print(sw)
            print(check(sw))
            print(re.fullmatch(r, sw))
            break
    else:
        print('Fine!')
