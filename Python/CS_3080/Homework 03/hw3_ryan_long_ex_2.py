'''
Homework 3, Exercise 2
Number of occurrences
Ryan Long
9/22/2020

This program prints the number of occurrences of chars in a string.
Letters are case-sensitive, and letters, punctuation, and white space is counted.
'''

import pprint

myString = "The quick brown fox jumps over the lazy dog"

# Create an empty dictionary
charDic = {}

# Populate the dictionary
for i in myString:
    if i in charDic:
        charDic[i] += 1
    else:
        charDic[i] = 1

# Print the dictionary
print("Contents of: " + myString)
pprint.pprint(charDic)

input("\nPress Enter to exit\n")

