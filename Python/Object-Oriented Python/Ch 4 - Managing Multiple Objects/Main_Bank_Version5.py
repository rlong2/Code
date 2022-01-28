# Main program for controlling a Bank made up of Accounts

from Bank import *

# Create a Bank object
oBank = Bank()

# Main code
# Loop through menu options
while True:
    print()
    print("Press b to get the balance")
    print("Press d to make a deposit")
    print("Press o to open a new account")
    print("Press c to close an existing account")
    print("Press w to make a withdrawl")
    print("Press s to show all accounts")
    print("Press a to display bank hours and other information")
    print("Press q to quit")
    print()

    action = input("What do you want to do? ")
    action = action[0].lower() # Grab the first letter, make it lowercase
    print()

    if action == 'b':
        oBank.balance()
    elif action == 'd':
        oBank.deposit()  
    elif action == 'o':
        oBank.openAccount() 
    elif action == 'c':
        oBank.closeAccount()
    elif action == 'w':
        oBank.withdraw()
    elif action == 's':
        oBank.show()
    elif action == 'a':
        oBank.about()
    elif action == 'q':
        print("*** Quitting... ***")
        break
    else:
        print("Invaid input, try again.")
