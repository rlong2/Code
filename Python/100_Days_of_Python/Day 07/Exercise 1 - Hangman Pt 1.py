import random

#Step 1 
word_list = ["aardvark", "baboon", "camel"]

# Randomly choose a word from the word_list and assign it to a variable called chosen_word.
chosen_word = random.choice(word_list)

# Ask the user to guess a letter and assign their answer to a variable called guess. Make guess lowercase.
guess = input("Guess a letter: ").lower()

# Check if the letter the user guessed (guess) is one of the letters in the chosen_word.
if guess in chosen_word:
    print(f"{guess} is in the word {chosen_word}")
else:
    print(f"{guess} is not in the word {chosen_word}")