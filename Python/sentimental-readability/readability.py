conclusion = ['.', '?', '!']

text = input("Text: ")
text_array = text.split()

num_letters = 0
num_sent = 0
num_words = 0

for word in text_array:
    for letter in word:
        if letter.isalpha():
            num_letters += 1
        if letter in conclusion:
            num_sent += 1
    num_words += 1

if num_words == 0:
    num_words = 1

L = (num_letters / num_words) * 100
S = (num_sent / num_words) * 100

index = 0.0588 * L - 0.296 * S - 15.8
grade_level = round(index)

if grade_level < 1:
    print("Before Grade 1")
elif grade_level > 16:
    print("Grade 16+")
else:
    print(f"Grade {grade_level}")
