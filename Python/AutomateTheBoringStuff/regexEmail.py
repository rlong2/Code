# This program finds email addresses

import re

emailStr = '''Valid emails are rlong@colorado.edu, ryan_long@protonmail.ch, r-long@gmail.com,
invalid emails are rlong@gmailcom, rl*78@yahoo.com, rlong2#yahoo.com, rlong(@gmail3.com '''

Lstring = '''lions Leopards zebras cats lemons algorithms '''
lRegex = re.compile(r'\bl[\w]+')
print(lRegex.findall(Lstring))

# [letters, nums, underscores]@[letters].[letters]
emailRegex = re.compile(r'\b[A-Za-z][A-Z|a-z|0-9|_|-]+\@[\w]+\.[\w]+')

print(emailRegex.findall(emailStr))
