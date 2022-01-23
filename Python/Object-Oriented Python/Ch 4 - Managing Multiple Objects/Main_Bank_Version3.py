# Create a dictionary of accounts to make deletion easier to manage

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

print("calling methods on the two accounts...")
accountsDict[ryansAccountNumber].deposit(50, "ryanpassword")
accountsDict[larrysAccountNumber].withdraw(20, "larrypassword")

# Create a third account interactively
userName = input("Enter the username for the account: ")
userBalance = int(input("Enter the starting balance for the account: "))
userPassword = input("Enter the password for the user: ")

# Add the new acount to the dictionary
oAccount = Account(userName, userBalance, userPassword)
newAccountNumber = nextAccountNumber
accountsDict[newAccountNumber] = oAccount
nextAccountNumber += 1

# Add some cash to the new account
accountsDict[newAccountNumber].deposit(450, userPassword)



