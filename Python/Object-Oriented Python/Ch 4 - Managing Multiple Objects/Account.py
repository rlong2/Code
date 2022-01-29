# A bank account class. It can deposit, withdraw, and check status.
# Errors will be caught by "raise" statements.

# Custom exception
class AbortTransaction(Exception):
    '''raise this exception to abort a bank transaction'''
    pass

class Account():
    def __init__(self, name, balance, password):
        self.name = name
        self.balance = int(balance)
        self.password = password

    def validateAmount(self, amount):
        try:
            amount = int(amount)
        except ValueError:
            raise AbortTransaction("Amount must be an integer.")
        if amount <= 0:
            raise AbortTransaction("Amount must be positive.")
        return amount

    def checkPasswordMatch(self, password):
        if password != self.password:
            raise AbortTransaction("Incorrect password for this account.")

    def getBalance(self, password):
        return self.balance
    
    def deposit(self, amountToDeposit, password):
        amountToDeposit = self.validateAmount(amountToDeposit)
        self.balance += amountToDeposit
        return self.balance

    def withdraw(self, amountToWithdraw, password):
        amountToWithdraw = self.validateAmount(amountToWithdraw)
        if amountToWithdraw > self.balance:
            raise AbortTransaction("You cannot withdraw more than you have in your account.")
        self.balance = self.balance - amountToWithdraw
        return self.balance
        
    # Debugging
    def show(self):
        print(f"Name: {self.name}")
        print(f"Balance: ${self.balance}")
        print(f"Password: {self.password}")
        print()
