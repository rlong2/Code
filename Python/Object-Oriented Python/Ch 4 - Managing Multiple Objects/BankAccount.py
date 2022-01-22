# A bank account class. It can deposit, withdraw, and check status.

class Account():
    def __init__(self, name, password, balance):
        self.name = name
        self.password = password
        self.balance = int(balance)

    def deposit(self, amountToDeposit, password):
        if password == self.password:
            if amountToDeposit < 0:
                print("You cannot deposit a negative amount")
                return None

            self.balance = self.balance + amountToDeposit
            return self.balance
        
        else:
            print("Sorry, incorrect password!")
            return None

    def withdraw(self, amountToWithdraw, password):
        if password == self.password:
            pass
        else:
            print("Sorry, incorrect password!")
            return None

    def getBalance(self, password):
        if password == self.password:
            return self.balance
        else:
            print("Sorry, incorrect password!")
            return None

    # Debugging
    def show(self):
        print(f"Name: {self.name}")
        print(f"Balance: {self.balance}")
        print(f"Password: {self.password}")
        print()
        
         
