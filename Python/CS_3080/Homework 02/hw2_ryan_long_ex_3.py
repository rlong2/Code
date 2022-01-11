'''
Homework 2, Exercise 3
Guess the Number
Ryan Long
9/14/2020

This program creates a list of strings and modifies it.
The program tells the user how the list has been modified.
A function is also called to nicely format items in the list.
'''

# Create a list
myList = ["Wallet", "Phone", "Keys"]
print("List created\n")

print(*myList, end = ' ')
print(              "            <--- print list using single line of code")

# Sort, then print again
myList.sort()
print(*myList, end = ' ')
print(               "            <--- Sort, then print again")

# First item in list
print(myList[0], end = ' ')
print(  "                         <--- First item in list")

# Everything except first item in list
print(*myList[1:], end = ' ')
print(          "                 <--- Everything except first item in list")

# Last item in list
print(myList[-1], end = ' ')
print(    "                       <--- Last item in list")

#Index of 'Keys'
print(myList.index('Keys'), end = ' ')
print("                            <--- Index of 'Keys'")

# list with tablet appended
myList.append("Tablet")
print(*myList, end = ' ')
print(                       "     <--- List with 'Tablet' appended")

# insert 'Mask' into list as 2nd item, print
myList.insert(1, "Mask")
print(*myList, end = ' ')
print(                       "<--- Insert 'Mask' into list as 2nd item")

# Remove 'Phone' from list, print
myList.remove("Phone")
print(*myList, end = ' ')
print("      <--- Remove 'Phone' from list")

# Reverse the list, print
myList.reverse()
print(*myList, end = ' ')
print("      <--- Reverse the list")

# This function takes the current string list as an argument
# and returns a string with all items separated by a comma, space,
# and 'and' before last item. Ex Phone, Mask, and Keys
def list_formatter(myList):
        front_of_list = myList[:-1]
        last_item = myList[-1]
        front_of_list.append('and')
        comma_string = ', '.join(front_of_list)
        formatted_string = comma_string + " " + str(last_item)
        return formatted_string

print("\nFormatting the list using list_formatter function...")
print(list_formatter(myList))

print("\nTesting function with other strings...")
print(list_formatter(["Eggs", "Bacon", "Sausage", "Spam"]))
print(list_formatter(["Kali", "sxmo", "Ubuntu", "GNU", "Penguins"]))

input("\nPress any key to exit")
