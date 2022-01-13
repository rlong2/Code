# findall returns lists of strings

import re

lyrics = '''On the twelfth day of Christmas
my true love sent to me:
12 Drummers Drumming
11 Pipers Piping
10 Lords a Leaping
9 Ladies Dancing
8 Maids a Milking
7 Swans a Swimming
6 Geese a Laying
5 Golden Rings
4 Calling Birds
3 French Hens
2 Turtle Doves
and 1 Partridge in a Pear Tree'''

# find n of a word, ie 12 Drummers
xmasRegex = re.compile(r'\d+ \w+')  # 1 or more digits, space, 1 or more letters
print(xmasRegex.findall(lyrics))

vowelRegex = re.compile(r'[aeiouAEIOU]') # find all vowels in a string
print(vowelRegex.findall('Robocop eats baby food'))

doubleVowelRegex = re.compile(r'[aeiouAEIOU]{2}') # find 2 vowels in a row
print(doubleVowelRegex.findall('Robocop eats baby food'))

## find everything trhat ISN'T a vowel
notDoubleVowelRegex = re.compile(r'[^aeiouAEIOU]') # note the ^
print(notDoubleVowelRegex.findall('Robocop eats baby food'))
