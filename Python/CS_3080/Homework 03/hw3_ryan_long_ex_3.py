'''
Homework 3, Exercise 3
Inventory
Ryan Long
9/22/2020

This program saves a given inventory into a data structure.
Functions exist to print the inventory, add items, and delete items.
'''

def printMenu():
    print("\nMenu Choices: ")
    print("1: Print inventory")
    print("2: Add item to inventory")
    print("3: Remove item from inventory")
    print("4: Exit program")
    
def printInventory(inventory):
    print("Item\t\tNumber of item")

    for key, value in inventory.items():
        print('{:<15}'.format(key), value)

def addItem(inventory, item):
    if item in inventory:
        inventory[item] +=1
        print("Added another " + item + " to inventory")
    else:
        inventory[item] = 1
        print("Added " + item + " to inventory")    

def deleteItem(inventory, item):
    if item in inventory:
        if inventory[item] > 0:
            inventory[item] -=1
            print("Removed " + item + " from inventory")
        else:
            print("No " + item + " in stock right now")
    else:
        print(item + " doesn't exist in inventory. ")   


# main
inventory = {'Hand sanitizer': 10,
             'Soap': 6,
             'Kleenex': 22,
             'Lotion': 16,
             'Razors': 12 }

print("Inventory stocked with default items")
                   
choice = 0
printMenu()

while choice != 4:
    choice = int(input("\nYour choice: "))

    if choice == 1:
        printInventory(inventory)
    elif choice == 2:
        item = input("Enter the item to add: ")
        addItem(inventory, item)
    elif choice == 3:
        item = input("Enter the item to remove: ")
        deleteItem(inventory, item)
    elif choice == 4:
        break
    else:
        print("You pressed the wrong key...")

print("Thanks for using the program!")
