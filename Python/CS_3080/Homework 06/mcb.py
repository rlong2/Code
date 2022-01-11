'''
Homework 6, Exercise 3
Multiclipboard
Ryan Long
11/11/2020

***********************************************************************************************
* NOTE: This program works correctly when calling 'python' instead of 'python3' on my machine *
***********************************************************************************************

This program copies multiple pieces of text to the clipboard,
each saved under a keyword.

Example:
python mcb.py save spam
Makes the current contents of the clipboard be saved under keyword 'spam'.
'spam' contents can be loaded to the clipboard by running: python mcb.py spam

Users can recall keyword by running: python mcb.py list

In total, here's how the program works:
1) Check the command line argument
2) If the arg == 'save', the current clipboard contents are saved under the keyword.
3) If the arg is 'list', then all the saved keywords are printed.
4) Else, if only a keyword is provided and no save or list is in the args,
the text saved under this keyword is copied to the clipboard.
'''

import pyperclip
import shelve
import sys

clipShelf = shelve.open('clipboard')

#Save current clipboard content under a keyword
if sys.argv[1] == 'save':
    clipShelf[sys.argv[2]] = pyperclip.paste()
    print("Saved clipboard contents uder keyword " + sys.argv[2])

# List keywords
elif sys.argv[1] == 'list':
        print("Clipboard keywords: " + str(list(clipShelf.keys())))

# Copy keyword contents to clipboard
elif sys.argv[1] in clipShelf:
    pyperclip.copy(clipShelf[sys.argv[1]])
    print("Copied contents of keyword " + sys.argv[1] + " to clipboard")

else:
    print('''
    Invalid input. Here's how the program works:
    python mcb.py save spam          # saves clipboard contents under keyword 'spam'
    python mcb.py list               # Display keywords that hold clipboard contents
    python mcb.py spam               # Load the contents of keyword 'spam' to your clipboard
    
    ''')
    
clipShelf.close()


