# Bagels: Guess the number based on clues

import random

NUM_DIGITS = 3
MAX_GUESSES = 10

def main():
    print('''
I am thinking of a a {}-digit number with no repeated digits.
Try to guess what it is. Here are some clues:
When I say:        That means:
    Pico           One digit is correct but in the wrong position.
    Fermi          One digit is correct and in the right position.
    Bagels         No digit is correct.

For example, if the secret number was 248 and your guess was 843, the
clues would be Fermi Pico'''.format(NUM_DIGITS))

    while True:     # main game loop
        secretNum = getSecretNum()
        print("I have thought of a random number.")
        print("You have {} guesses to get it.".format(MAX_GUESSES))
#        print("secretNum is ", secretNum) # REMOVE

        numGuesses = 1

        while numGuesses <= MAX_GUESSES:
            # Prompt for guess
            guess = ''
            # Keep looping until user inputs a valid guess
            while len(guess) != NUM_DIGITS or not guess.isdecimal():
                print('Guess #{}: '.format(numGuesses))
                guess = input('> ')

            clues = getClues(guess, secretNum)
            print(clues)
            numGuesses += 1

            if guess == secretNum:
                break               # user is correct, break out of while loop
            if numGuesses > MAX_GUESSES:
                print("You ran out of guesses")
                print("The answer was {}".format(secretNum))

        # Ask player if they want to play again
        print("Do you want to play again? (yes or no)")
        if not input('> ').lower().startswith('y'):
            break

    print("Thanks for playing!")

# Returns a string made up of NUM_DIGITS with unique random digits
def getSecretNum():
    numbers = list('0123456789')
    random.shuffle(numbers)
    # Get the first NUM_DOGOTS digits in the list for the secret number
    secretNum = ''
    for i in range(NUM_DIGITS):
        secretNum += str(numbers[i])
    return secretNum

# Returns a string with the pico, fermi, bagels clues for a guess
def getClues(guess, secretNum):
    if guess == secretNum:
        return "You got it!"

    clues = []

    for i in range(len(guess)):
        if guess[i] == secretNum[i]:    # A correct digit in the correct place
            clues.append('Fermi')
        elif guess[i] in secretNum:     # A correct digit in the incorrect place
            clues.append('Pico')
    if len(clues) == 0:         # No correct digits at all
        return 'Bagels'
    else:               # Sort clues into alphabetical order so that original order
        clues.sort()    # doesn't give extra information away
        return ' '.join(clues)  # return a single string

# If the program is run (instead of imported), run the game:
if __name__ == '__main__':
    main()

