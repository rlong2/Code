# Create a dictionary of accounts to make deletion easier to manage
# This version has an interactive menu

from Account import *

accountsDict = {}
nextAccountNumber = 0

# Create two accounts
oAccount = Account("Ryan", 100, "ryanpassword")
ryansAccountNumber = nextAccountNumber
accountsDict[ryansAccountNumber] = oAccount
nextAccountNumber += 1

oAccount = Account("Larry", 320, "larrypassword")
larrysAccountNumber = nextAccountNumber
accountsDict[larrysAccountNumber] = oAccount
nextAccountNumber += 1

while True:
    print()
    print("Press b to get the balance")
    print("Press d to make a deposit")
    print("Press o to open a new account")
    print("Press w to make a withdrawl")
    print("Press s to show all accounts")
    print("Press q to quit")
    print()

    action = input("What do you want to do? ")
    action = action[0].lower() # Grab the first letter, make it lowercase
    print()

    if action == 'b':
        print("*** Get Balance ***")
        userAccountNumber = int(input("Enter your account number: "))
        userAccountPassword = input("Enter your account password: ")
        oAccount = accountsDict[userAccountNumber]
        theBalance = oAccount.getBalance(userAccountPassword)
        print(f"Your balance is ${theBalance}")
        
    elif action == 'd':
        print("*** Make a Deposit ***")
        userAccountNumber = int(input("Enter your account number: "))
        userAccountPassword = input("Enter your account password: ")
        amountToDeposit = int(input("Enter the amount to deposit: "))
        oAccount = accountsDict[userAccountNumber]
        oAccount.deposit(amountToDeposit, userAccountPassword)
        
    elif action == 'o':
        print("*** Open an Account ***")
        userName = input("Enter a username for the new account: ")
        userBalance = int(input("Enter the starting balance for the account: "))
        userPassword = input("Enter the password for the user: ")
        oAccount =  Account(userName, userBalance, userPassword)
        accountsDict[nextAccountNumber] = oAccount
        print(f"Your new account number is: {nextAccountNumber}")
        nextAccountNumber += 1
        print()
        
    elif action == 'w':
        print("Make a Withdrawl")
        userAccountNumber = int(input("Enter your account number: "))
        userAccountPassword = input("Enter your account password: ")
        amountToWithdraw = int(input("Enter the amount to withdraw: "))
        oAccount = accountsDict[userAccountNumber]
        oAccount.withdraw(amountToWithdraw, userAccountPassword)
        
    elif action == 's':
        print("*** Show all Accounts ***")
        for userAccountNumber in accountsDict:
            oAccount = accountsDict[userAccountNumber]
            print(f"Account number: {userAccountNumber}")
            oAccount.show()
        
    elif action == 'q':
        print("*** Quitting... ***")
        break
        
    else:
        print("Invalid input, try again!")

