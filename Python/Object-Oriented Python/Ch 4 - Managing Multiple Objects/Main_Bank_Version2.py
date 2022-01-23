# Test program using accounts
# Version 2, using a list of accounts

from Account import *

# Create an empty list of accounts
accountsList = []

# Create two accounts
oAccount = Account("Ryan", 100, "ryanpass")
accountsList.append(oAccount)

oAccount = Account("Larry", 4000, "Larrypassword")
accountsList.append(oAccount)

# Print the acount information
accountsList[0].show()
accountsList[1].show()

# Call some methods on the different accounts
print(f"Calling some methods on the {len(accountsList)} accounts...")
accountsList[0].deposit(50, "ryanpass")
accountsList[1].withdraw(345, "Larrypassword")
accountsList[1].deposit(100, "Larrypassword")

# Print the acount information
print()
accountsList[0].show()
accountsList[1].show()

# Create a third account interactively
userName = input("Enter the username for the account: ")
userBalance = int(input("Enter the starting balance for the account: "))
userPassword = input("Enter the password for the user: ")

# Append the new acount to the list
oAccount = Account(userName, userBalance, userPassword)
accountsList.append(oAccount)

# Show the new user account
accountsList[2].show()

# Deposit some cash into the new account
accountsList[2].deposit(1000, userPassword)
