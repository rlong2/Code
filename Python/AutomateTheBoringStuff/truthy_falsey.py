print('Enter a name:')
name = input()

#if name:        # If the string is 'truthy', ie not a blank 'falsey' string...
if name != '':   # Better: if name is not blank...
    print('Hi ' + name)
else:
    print('You did not enter a name!')
