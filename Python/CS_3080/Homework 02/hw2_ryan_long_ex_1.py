'''
Homework 2, Exercise 1
Collatz Sequence
Ryan Long
9/14/2020

This program takes an integer and runs it through the 'Collatz Sequence'
until the output is 1.

The Collatz Sequence is this:
If the number is even, the function prints n // 2 and returns the value
If the number is odd, print 3 * n + 1 and returns the value
'''

def collatz(number):
    if (number % 2 == 0):
        print(str(number // 2))
        return number // 2
    else:
        print(str((3 * number) + 1))
        return (3 * number) + 1

# call collatz function until result is 1
print("Enter number: ")
n = int(input())

while (n) != 1:
    n = collatz(n)

input('\nPress Enter to Exit')
