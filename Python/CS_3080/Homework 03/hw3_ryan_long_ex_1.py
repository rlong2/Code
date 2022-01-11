'''
Homework 3, Exercise 1
Character Picture Grid
Ryan Long
9/21/2020

This program prints out a given grid, it's a heart!
'''

grid = [['.', '.', '.', '.', '.', '.'],
        ['.', 'O', 'O', '.', '.', '.'],
        ['O', 'O', 'O', 'O', '.', '.'],
        ['O', 'O', 'O', 'O', 'O', '.'],
        ['.', 'O', 'O', 'O', 'O', 'O'],
        ['O', 'O', 'O', 'O', 'O', '.'],
        ['O', 'O', 'O', 'O', '.', '.'],
        ['.', 'O', 'O', '.', '.', '.'],
        ['.', '.', '.', '.', '.', '.']]

print("Printing the 2D array...\n")
for i in range(len(grid[0])):
    for j in range(len(grid)):
        print(grid[j][i], end = " ")
    print()