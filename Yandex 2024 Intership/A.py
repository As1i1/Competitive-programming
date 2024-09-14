text = input()
words = []
words_not_formatted = []
current_word = ""
for i in range(len(text)):
    if text[i].isalpha():
        current_word += text[i]
    elif len(current_word) > 0:
        words.append(current_word)
        words_not_formatted.append(current_word)
        current_word = ""
    if text[i] == ',':
        words_not_formatted[-1] += ","
if len(current_word) > 0:
    words.append(current_word)
    words_not_formatted.append(current_word)
ln = max(map(len, words)) * 3
cur_len = len(words_not_formatted[0])
print(words_not_formatted[0], end="")
for word in words_not_formatted[1:]:
    if len(word) + cur_len + 1 > ln:
        cur_len = len(word)
        print("\n" + word, end="")
    else:
        print(" " + word, end="")
        cur_len += len(word) + 1