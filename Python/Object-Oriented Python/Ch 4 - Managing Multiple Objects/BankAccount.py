# A bank account class. It can deposit, withdraw, and check status.

class Account():
    def __init__(self, name, password, balance):
        self.name = name
        self.password = password
        self.balance = int(balance)

    def deposit(self, amountToDeposit, password):
        pass

    def withdraw(self, amountToWithdraw, password):
        pass

    def getBalance(self, password):
        pass

    # Debugging
    def show(self):
        print(f"Name: {self.name}")
        print(f"Balance: {self.balance}")
        print(f"Password: {self.password}")
        print()
        
         
