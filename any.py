import random
import string


def solve1(s, t):
    a = []
    for i in t:
        a.append([s.count(i), i])
    a.sort(key=lambda x: -x[0])
    slow = {}
    while len(a) != 1:
        a1 = a.pop()
        a2 = a.pop()
        for e in a1[1]:
            slow[e] = '1' + slow.get(e, '')
        for e in a2[1]:
            slow[e] = '0' + slow.get(e, '')
        a.append([a1[0] + a2[0], a1[1] + a2[1]])
        a.sort(key=lambda x: -x[0])
    b = []
    for e in a[0][1]:
        b.append([e, slow[e]])
    b.sort(key=lambda x:len(x[1]), reverse=True)
    return b


def stress():
    while True:
        n = random.randint(500, 600)
        t = string.ascii_letters
    #    print(t)
    #    s1 = 'ahefffdhhbgfeefdgeccefahgeaeageeaaegdhggbgacfhefcafabcchgbdeeaaaeggccegbgcaghfebedfhffeahefedegfadehhegccebbeafadhbhfcaecdfdgdbegccefdcfhdfchheabffbeehefehcgeeedcacahgbgggcdegbhfegchgf'
        s1 = ''.join([t[random.randint(0, len(t) - 1)] for _ in range(n)])
        ans1 = solve1(s1, t)
        s2 = ans1[0][0]
        k = 1
        slow = {ans1[0][0]:ans1[0][1]}
        for i in range(1, len(ans1)):
            if len(ans1[i][1]) != len(ans1[i - 1][1]):
                k *= (2 ** (len(ans1[i - 1][1]) - len(ans1[i][1])))
            slow[ans1[i][0]] = ans1[i][1]
            s2 += ans1[i][0] * k
        ans2 = solve1(s2, t)
        for i in ans2:
        #    print(s1, s2)
            if len(slow[i[0]]) != len(i[1]):
                print("ERROR")
                print(s1)
                print(s2)
                quit(1)


def f2():
    n = 33
    a = []
    for i in range(n):
        x, y = input().split()
        y = int(float(y.replace(',', '.')) * 1000)
        a.append([y, x[0]])
    a.sort(key=lambda x: -x[0])
    slow = {}
    while len(a) != 1:
        a1 = a.pop()
        a2 = a.pop()
        for e in a1[1]:
            slow[e] = '0' + slow.get(e, '')
        for e in a2[1]:
            slow[e] = '1' + slow.get(e, '')
        a.append([a1[0] + a2[0], a1[1] + a2[1]])
        a.sort(key=lambda x: -x[0])
    b = []
    cnt0, cnt1, cnt2 = 0, 0, 0
    for k, v in slow.items():
        b.append([k, v])
        if len(v) == 6:
            cnt1 += 1
        elif len(v) < 6:
            cnt0 += 1
        elif len(v) > 6:
            cnt2 += 1
    print(cnt0, cnt1, cnt2)
    b.sort(key=lambda x:len(x[1]))
    print(*b, sep='\n')


if __name__ == "__main__":
    f2()