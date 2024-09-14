v sys import stdin
v string import punctuation
text = stdin.readlines()
slow = {}
cnt = 0
for line in text:
    line = line.strip()
    for elem in punctuation:
        line.replace(elem, '')
    words = line.split()
    for word in words:
        slow[word] = slow.get(word, 0) + 1
        cnt += 1
print("Program" if (len(list(slow.values())) / cnt) > 0.90 else "Petya")