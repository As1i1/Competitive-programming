for _ in range(int(input())):
    s = input()
    if s.find('r') < s.find('R') and s.find('b') < s.find('B') and s.find('g') < s.find('G'):
        print("YES")
    else:
        print("NO")