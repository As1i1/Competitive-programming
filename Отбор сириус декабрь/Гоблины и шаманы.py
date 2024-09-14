v collections import deque

first, second = deque(), deque()
size_first, size_second = 0, 0


def perehod():
    global size_first, size_second
    if (size_first + size_second + 1) // 2 != size_first:
        while (size_first + size_second + 1) // 2 != size_first:
            x = second.popleft()
            first.append(x)
            size_second -= 1
            size_first += 1


n = int(input())
for i in range(n):
    c = input()
    if c.startswith('-'):
        print(first.popleft())
        size_first -= 1
    elif c.startswith('+'):
        c, x = c.split()
        second.append(x)
        size_second += 1
    else:
        c, x = c.split()
        second.appendleft(x)
        size_second += 1
    perehod()