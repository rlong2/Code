# Main program for controlling a Bank made up of Accounts

from Bank import *

# Create a Bank object
oBank = Bank()

# Main code
# Create two test accounts
larrysAccountNumber = oBank.createAccount("Larry", 1000, "larrypass")
oBank.balance()
