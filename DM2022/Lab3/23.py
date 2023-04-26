s = input()
n = int(s, 2)
if '1' not in s:
    print('-')
    print(bin(n + 1)[2:].rjust(len(s), '0'))
elif '0' not in s:
    print(bin(n - 1)[2:].rjust(len(s), '0'))
    print('-')
else:
    print(bin(n - 1)[2:].rjust(len(s), '0'))
    print(bin(n + 1)[2:].rjust(len(s), '0'))