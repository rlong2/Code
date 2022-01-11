'''
Homework 4, Exercise 4
Password Locker
Ryan Long
10/16/2020

This program evaluates given passwords using regex to see if they are secure.
A password is considered strong if the string:
    1) is at least 8 characters long
    2) contains uppercase and lowercase letters
    3) contains at least one digit
'''

import re

pwRegex = re.compile(r'''(
    (?=.*[A-Z])         # at least one capital letter
    (?=.*[a-z])         # at least one lowercase letter
    (?=.*[0-9])         # at least one digit
    .{8,}               # at least 8 characters long
    $                   # end of regex
    )''', re.VERBOSE)

def isPasswordSecure():
    pw = input("Enter a password to check: ")
    mo = pwRegex.search(pw)
    if (not mo):
        print("Your password isn't secure!")
        return False
    else:
        print("Your password is secure!")
        return True

# Call function
isPasswordSecure()