# Test program using acounts
# Version 1, using explicit vars for eact Account object

# import all code from the Account class
from Account import *

# Create two accounts
oLarrysAccount = Account("Larry", 1200, "qwerty")
print(f"Created account for {oLarrysAccount.name}")

oRyansAccount = Account("Ryan", 5, "p@ssw0rd")
print(f"Created account for {oRyansAccount.name}")
print()

oLarrysAccount.show()
oRyansAccount.show()

# Call some methods on the different accounts
print("Calling some methods to alter account data...\n")
oLarrysAccount.deposit(3000, "qwerty")
oRyansAccount.withdraw(4, "p@ssw0rd")

# Display account info
oLarrysAccount.show()
oRyansAccount.show()

# Create a third account interactively
userName = input("Enter the username for the account: ")
userBalance = int(input("Enter the starting balance for the account: "))
userPassword = input("Enter the password for the user: ")
oNewAccount = Account(userName, userBalance, userPassword)
print()

# Display the new user's account, modify, and show again
oNewAccount.show()
oNewAccount.deposit(4444, userPassword)
oNewAccount.show()
oNewAccount.withdraw(583, userPassword)
oNewAccount.show()
