'''
Homework 2, Exercise 4.3
Guess the Number: The computer plays for you
Ryan Long
9/14/2020

This is a 'guess the number' program that makes winning more difficult
by generating a random number between random upper and lower bounds
for each attempt. The computer plays for you and takes no user input.
'''

import random

num_guesses = 10
tries_remaining = 10
count = 0

while True:
    rand_lower = random.randint(1, 10)                  # Generate lower bound
    rand_upper = random.randint(11, 20)                 # Generate upper bound
    rand_int = random.randint(rand_lower, rand_upper)   # Generate random integer in between the bounds
    comp_num = random.randint(rand_lower, rand_upper)   # The computer picks a random integer in between the bounds

    print("I am thinking of a number between " + str(rand_lower) + " and " + str(rand_upper) + ". The computer has " + str(tries_remaining) + " tries.")
    print("The computer picks " + str(comp_num))
    count += 1
    tries_remaining -= 1

    if count == num_guesses:
        print("\nSorry, the number I was thinking of was " + str(rand_int))
        break
    elif comp_num == rand_int:
        print("\nWoohoo! The computer guessed the number in " + str(count) + " tries!")
        break
    elif comp_num > rand_int:
        print("The guess guess is too high.")
    elif comp_num < rand_int:
        print("The guess is too low.")

input("\nPress any key to exit")
