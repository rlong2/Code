#Step 3

import random
word_list = ["aardvark", "baboon", "camel"]
chosen_word = random.choice(word_list)
word_length = len(chosen_word)

#Testing code
print(f'Pssst, the solution is {chosen_word}.')

#Create blanks
display = []
for _ in range(word_length):
    display += "_"

#Use a while loop to let the user guess again.
#The loop should only stop once the user has guessed all the letters in the chosen_word and 'display' has no more blanks ("_").
#Then you can tell the user they've won.

# Create a display_string to convert the list
# display_string is rebuilt inside each while loop to compare the chosen_word to the user's guesses
display_string = ""                     
while chosen_word != display_string:
    display_string = ""
    guess = input("Guess a letter: ").lower()

    #Check guessed letter
    for position in range(word_length):
        letter = chosen_word[position]
        if letter == guess:
            display[position] = letter

    display_string = display_string.join(display)
    print(display)
print("You win!")
