from re import findall


# Get the text input from the user
text = input("Text: ")


# Count the number of letters, words, and sentences in the text
letters = len(findall("[a-zA-Z]", text))
words = len(text.split())
sentences = len(findall("[.!?]", text))


# Calculate the Coleman-Liau index
L = (letters / words) * 100
S = (sentences / words) * 100
index = 0.0588 * L - 0.296 * S - 15.8


# Print the grade level
if index >= 16:
    print("Grade 16+")
elif index < 1:
    print("Before Grade 1")
else:
    print(f"Grade {round(index)}")