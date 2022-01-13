# This program is a guess-the-number style game

import random

MIN = 1
MAX = 20

randNum = (random.randint(MIN, MAX))

# Welcome
print('Hello, what\'s your name?')
name = input()
print('Hi ' + name + ', I\'m thinking of a number between ' + str(MIN) + ' and ' + str(MAX))

# Play the game!
for guessesTaken in range(1,7):

    print('Take a guess:')
    guess = int(input())

    if guess < randNum:
        print('Too low.')
    elif guess > randNum:
        print('Too high.')
    else:                     # correct guess
        break

# Print success or failure
if guess == randNum:
    if guessesTaken == 1:
        print('You guessed the number in ' + str(guessesTaken) + ' try!')    # print 'try'
    else:                                                                    # if 1 guess
        print('You guessed the number in ' + str(guessesTaken) + ' tries!')  # vs 'tries'
else:
    print('Nope, the number I was thinking of was ' + str(randNum))
