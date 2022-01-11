'''
Homework 2, Exercise 4.1
Guess the Number
Ryan Long
9/14/2020

This is a simple 'guess the number' program
'''

import random

rand_int = random.randint(1, 20)
num_guesses = 10
count = 0

print("I am thinking of a number between 1 and 20 (inclusive). You have " + str(num_guesses) + " tries.")

while True:
    user_num = int(input("Take a guess: "))
    count += 1

    if count == num_guesses:
        print("\nSorry, the number I was thinking of was " + str(rand_int))
        break
    elif user_num == rand_int:
        print("\nGood job! You guessed the number in " + str(count) + " guesses!")
        break
    elif user_num > rand_int:
        print("Your guess is too high.")
    elif user_num < rand_int:
        print("Your guess is too low.")

input("\nPress any key to exit")

