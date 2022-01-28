# A Bank class that manages a dictionary of Account objects

from Account import *

class Bank():
    def __init__(self):
        self.accountsDict = {}
        self.nextAccountNumber = 0

    def createAccount(self, name, startingAmount, password):
        oAccount = Account(name, startingAmount, password)
        newAccountNumber = self.nextAccountNumber
        self.accountsDict[newAccountNumber] = oAccount
        # Increment to prepare for next account to be created
        self.nextAccountNumber = self.nextAccountNumber + 1
        print(f"Your new account number is {newAccountNumber}")
        return newAccountNumber

    def openAccount(self):
        print("*** Open an Account ***")
        userName = input("Enter a username for the new account: ")
        userBalance = int(input("Enter the starting balance for the account: "))
        userPassword = input("Enter a password for the user: ")
        # Call createAccount method
        userAccountNumber = self.createAccount(userName, userBalance, userPassword)
        print(f"Your new account number is: {nextAccountNumber}")
        print()

    def closeAccount(self):
        print("*** Close Account ***")
        userAccountNumber = int(input("What is your account number?: "))
        userPassword = input("What is your password?: ")
        oAccount = self.accountsDict[userAccountNumber]
        balance = oAccount.getBalance(userPassword)
        print(f"You had ${balance} in your account, which is being returned to you.")
        del self.accountsDict[userAccountNumber]
        print("Your account is now closed.")

    def balance(self):
        print("*** Get Balance ***")
        userAccountNumber = int(input("Enter your account number: "))
        userAccountPassword = input("Enter your account password: ")
        oAccount = self.accountsDict[userAccountNumber]
        theBalance = oAccount.getBalance(userAccountPassword)
        print(f"Your balance is ${theBalance}")

    def deposit(self):
        print("*** Make a Deposit ***")
        userAccountNumber = int(input("Enter your account number: "))
        userAccountPassword = input("Enter your account password: ")
        amountToDeposit = int(input("Enter the amount to deposit: "))
        oAccount = self.accountsDict[userAccountNumber]
        oAccount.deposit(amountToDeposit, userAccountPassword)

    def withdraw(self):
        print("Make a Withdrawl")
        userAccountNumber = int(input("Enter your account number: "))
        userAccountPassword = input("Enter your account password: ")
        amountToWithdraw = int(input("Enter the amount to withdraw: "))
        oAccount = self.accountsDict[userAccountNumber]
        oAccount.withdraw(amountToWithdraw, userAccountPassword)

    def show(self):
        print("*** Show all Accounts ***")
        for userAccountNumber in self.accountsDict:
            oAccount = self.accountsDict[userAccountNumber]
            print(f"Account number: {userAccountNumber}")
            oAccount.show()

    def about(self):
        hours = "Monday through Friday, 8 AM to 5 PM"
        location = "Auckland, NZ"
        print(f"This bank is based in {location}.")
        print(f"The hours are {hours}.")

