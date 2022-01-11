'''
Homework 2, Exercise 4.2
Guess the Number: Upper and Lower bounds
Ryan Long
9/14/2020

This is a 'guess the number' program that makes winning more difficult
by generating a random number between random upper and lower bounds
for each attempt
'''

import random

num_guesses = 10
tries_remaining = 10
count = 0


while True:
    rand_lower = random.randint(1, 10)                  # Generate lower bound
    rand_upper = random.randint(11, 20)                 # Generate upper bound
    rand_int = random.randint(rand_lower, rand_upper)   # Generate random integer in between the bounds

    print("I am thinking of a number between " + str(rand_lower) + " and " + str(rand_upper) + ". You have " + str(tries_remaining) + " tries.")
    user_num = int(input("Take a guess: "))
    count += 1
    tries_remaining -= 1

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
