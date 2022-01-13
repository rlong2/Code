# This program grabs emails and phone numbers from text copied to the clipboard
# Tested using https://www.sde.idaho.gov/_files/SDE-Staff-Directory-Name.pdf

import pyperclip, re

print('This program grabs emails and phone numbers from text copied to the clipboard')
print('Make sure you have the text copied to the system clipboard.')
input('Press Enter to continue...')

# Create a regex for phone numbers
# Put everything in one large group to avoid tuples
phoneRegex = re.compile(r'''
# examples: 415-555-0000, 555-0000, (415) 555-0000, 555-0000 ext 12345, ext. 12345, x12345
(
((\d\d\d)|(\(\d\d\d\)))?       # area code (optional)
(\s|-)                         # first seperator
\d\d\d                         # first 3 digits
-                              # second seperator
\d\d\d\d                       # last 4 digits
(((ext(\.)?\s)|x)              # extension word part (optional)
 (\d{2,5}))?                   # extension number part (optional)
)
''', re.VERBOSE)

# Create a regex for email addresses
emailRegex = re.compile(r'''
# example: somet.+_hing@something.com

[a-zA-Z][a-zA-Z0-9_\-.+]+ # name part
@                # @ symbol
[a-z0-9_\-.+]+[a-z] # domain name part

''', re.VERBOSE)

# Get text from clipboard
text = pyperclip.paste()

# Extract the emails/phones from this text
extractedPhone = phoneRegex.findall(text)
extractedEmail = emailRegex.findall(text)

# Phone numbers appear at the beginning of each tuple
# To avoid garbage, get the first item (phone num) from each tuple
allPhoneNumbers = []
for phoneNumber in extractedPhone:
    allPhoneNumbers.append(phoneNumber[0]) # [0] is first string in tuple

# Copy the extracted email/phone to clipboard
results = '\n'.join(allPhoneNumbers) + '\n' + '\n'.join(extractedEmail)
pyperclip.copy(results)

print('Emails and phone numbers copied to system clipboard')
