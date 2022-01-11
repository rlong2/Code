'''
Homework 5, Exercise 3
The Generator Version of range()
Ryan Long
10/26/2020

This program uses a generator function to generate a range of values
The start and step arguments are optional
'''

def genrange(start, stop = None, step = None):
    if stop is None:
        i = 0
        while i <= start:
            yield i
            i += 1
    elif step is None:
        i = start
        while i <= stop:
            yield i
            i += 1
    else:
         i = start
         while i <= stop:
            yield i
            i += step

print("Calling function with start arg: (5)")
for r in genrange(5):
    print(r)

print("\nCalling function with start, stop arg: (5, 10)")
for r in genrange(5,10):
    print(r)

print("\nCalling function with start, stop, and step arg: (5, 10, 2)")
for r in genrange(5,10,2):
    print(r)
