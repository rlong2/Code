""""
Homework 1
Ryan Long
9/08/2020

This program is a faux security program that implements
python basics and flow control
"""

import random
from math import pi
from pathlib import Path

# Variables
play_again = True
question_list = [1, 2, 3]

def get_name():
    print("Hello, Secret Agent!")
    print("What is your secret code name?")
    name = str(input())
    if len(name) < 2:
        print("Terrible name, I'll just call you Bond")
        name = "Bond"
    print("Welcome, " + name + "!")
    return str(name)

def get_pin():
        print("Enter a 3-digit pin to verify your identity: ")
        pin = int(input())
        if len(str(pin)) != 3:
            print("Please read the instructions.")
            get_pin()
        return pin

def get_secret_code(name, pin):
    rand_num = random.randint(1,4)
    print("In order to unlock the treasure coordinates, enter THE SECRET CODE!")
    print("((Your pin backwards *  pi) / (characters in your name)) // " + str(rand_num)  +
          "\nOutput your result as an integer.")

    pin = str(pin)
    reversed_pin = pin[-1] + pin[1] + pin[0]

    code = (int(reversed_pin) * pi / len(name)) // 2
    code = int(code)

    user_code = int(input())

    if user_code == code:
        output_coordinates()

    else:
        print("Wrong!")
        bottomless_pit()
        get_secret_code(name, pin)

def bottomless_pit():
    falling = True
    escape_str = "gogogadgethelicopterhat"
    print("A bottomless pit opens and you fall into it!")
    while falling:
        print("woooosh!")
        print("type " + escape_str + " to escape!")
        user_str = str(input())

        if user_str != escape_str:
            print("You continue to fall!")
            continue
        else:
            print("You escaped the pit! What a break!")
            break

def output_coordinates():
    treasure_location = "27 22 50.10 N, 33 37 54.62 E"              # Desert Breath

    print("\nOutputting coordinates to buried treasure to a file!")
    text_file = open('treasure_map.txt', 'w')
    text_file.write(treasure_location)

    file_path = Path("treasure_map.txt").resolve()
    print(str(file_path))

while play_again:
    print("foo")
    for q in question_list:
        if q == 1:
            name = get_name()
        elif q == 2:
            pin = get_pin()
        elif q == 3:
            get_secret_code(name, pin)
        else:
            print("How did you get here?")

    # Ask if user would like to play again
    user_choice = input("\nPlay again? y/n: ")
    if user_choice != 'y':
        play_again = False