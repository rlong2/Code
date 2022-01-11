# Guess the Number game.

import random
import sys

MIN_NUM = 1
MAX_NUM = 20
MAX_TRIES = 6

# Make sure user enters an integer.
def getGuess():
    while True:
        try:
            guess = int(input("Guess the number: "))
            if guess < MIN_NUM or guess > MAX_NUM:
                print("The number is in the range of {} and {}, try another guess.".format(MIN_NUM, MAX_NUM))
                continue
            else:
                break
        except ValueError:
            print("Please input an integer")
            continue
    return guess

# Check if the user's guess is higher or lower than the secret number.            
def checkGuess(guess, randNum, attempts):
    if guess > randNum:
        print("Too high!")
        return False
    elif guess < randNum:
        print("Too low!")
        return False
    else:
        print("You guessed the right number in {} attempts!".format(attempts))
        correct = True
        return correct
    
def main():
    while True:
        correct = False
        randNum = random.randint(MIN_NUM, MAX_NUM)
        attempts = 0

        print("I am thinking of a number between {} and {}".format(MIN_NUM, MAX_NUM))
        print("You have {} attempts.".format(MAX_TRIES))

        while attempts < MAX_TRIES:
            guess = getGuess()
            attempts += 1
            correct = checkGuess(guess, randNum, attempts)
            if correct is True:
                play = input("You win!")
                break

        # If user does not guess the number in MAX_TRIES, they lose.        
        if correct is False:
            print("Out of tries! The correct number was {}".format(randNum))
            
        playAgain = (input("Play again? (yes/no): ")).lower()
        #playAgain = playAgain.lower()
        if playAgain.startswith('y'):
            continue
        else:
            print("Thanks for playing!")
            break
        

    
main()
