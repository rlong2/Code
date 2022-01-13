# Regex syntax for finding things at beginning, end of strings

import re

startsWithHelloRegex = re.compile(r'^Hello')
print(startsWithHelloRegex.findall('Hello Hello heloo'))

endsWithHelloRegex = re.compile(r'hi$')
print(endsWithHelloRegex.findall('hi Hello Hello hi heloo'))
print(endsWithHelloRegex.findall('hi Hello Hello hi heloo hi'))

worldRegex = re.compile(r'[Ww]orld!?$')
print(worldRegex.findall('Hello World!'))
print(worldRegex.findall('Hello world'))
print(worldRegex.findall('world hello!'))

exactRegex = re.compile(r'^must be exact$')
print(exactRegex.findall('must be exact'))
print(exactRegex.findall('must be exactly this'))

allDigitsRegex = re.compile(r'^\d+$') # all digits
print(allDigitsRegex.findall('432432'))
print(allDigitsRegex.findall('432fwe432'))

###############
# Printing anything (except new line char with .)
atRegex = re.compile(r'.at') # finds strings with chars ending in +at
print(atRegex.findall('The cat and the hat went up to bat like blat flat scat'))

atRegex = re.compile(r'.{1,2}at')
print(atRegex.findall('The cat and the hat went up to bat scat'))

# .* print any amount of anything (excluding new line)
# .* is greedy!
# .*? is not greedy
# Given String: First name: Ryan List Name: Long
nameRegex = re.compile(r'First Name: (.*) Last Name: (.*)') # create groups with
nameRegex.findall('First Name: Ryan Last Name: Long')

serve = '<To serve humans> for dinner.'
nonGreedyRegex = re.compile(r'<(.*?)>')
print(nonGreedyRegex.findall(serve))

