'''
Homework 4, Exercise 1
Password Locker
Ryan Long
10/08/2020

This program is a simple password manager.
It is run like so:
python3 hw4_ryan_long_ex_1.py <website>
Then the password to the website is copied to the clipboard.
'''

import pyperclip as pc
import sys

PassDic = {
    'instagram':'Insta-Super$ecret7!',
    'google':'00gle@g00gl3',
    'facebook':'faceb00k_uck9'
}

if len(sys.argv) < 2:
    print("Usage: python hw4_ryan_long_ex_1.py <website>")
    print("Choices are instagram, google, or facebook")
    sys.exit()
else:
    choice = sys.argv[1]
    if (choice in PassDic.keys()):
        pc.copy(PassDic[choice])
        print(choice + "password copied to clipboard")
    else:
        print(choice + " is not in the password vault.")
        sys.exit()