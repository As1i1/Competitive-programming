for _ in range(int(input())):
    n, s = map(int, input().split())
    n = n - ((n + 1) // 2 - 1)
  #  print(n)
    print(s // n)