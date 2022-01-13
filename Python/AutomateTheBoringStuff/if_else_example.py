# password = 'swordfish'
numTries = 0
MAX = 3

while (numTries < MAX):
    print('Enter password:')
    password = input()
    if password == 'swordfish':
        print('Logged in!')
        break
    else:
        print('Access Denied')
        numTries += 1
        print('You have ' + str(MAX - numTries) + ' tries remaining')

if (numTries >= MAX):
    print('\nYou are locked out of the system')
        
