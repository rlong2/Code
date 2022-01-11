'''
You are going to write a program that will mark a spot with an X.
Example: user input 32 marks an X at column 3, row 2
'''
# 🚨 Don't change the code below 👇
row1 = ["⬜","⬜️","⬜️"]
row2 = ["⬜️","⬜️","⬜️"]
row3 = ["⬜️","⬜️","⬜️"]
map = [row1, row2, row3]
print(f"{row1}\n{row2}\n{row3}")
position = input("Where do you want to put the treasure? ")
# 🚨 Don't change the code above 👆

#Write your code below this row 👇
row = int(position[0])
column = int(position[1])
map[column - 1][row - 1] = 'X'

#Write your code above this row 👆

# 🚨 Don't change the code below 👇
print(f"{row1}\n{row2}\n{row3}")