input_String = input()
word_list = input_String.split(" ")
blank_count = 0

if (word_list[0] == ""):
    blank_count += 1

if (word_list[len(word_list) - 1] == ""):
    blank_count += 1

if (blank_count == 1):
    print(len(word_list) - 1)

elif (blank_count == 2):
    print(len(word_list) - 2)

else:
    print(len(word_list))