'''
Homework 5, Exercise 2
Pythogorian triplets
Ryan Long
11/02/2020

This program uses a generator comprehension expression to find the
first 10 (or any n) pythagorean triplets.
A triplet (x,y,z) is a pythagorean triplet if x*x + y*y == z*z for all integers.


Example:
print(take(10, pyt))
Output:
[(3, 4, 5), (6, 8, 10), (5, 12, 13), (9, 12, 15),
(8, 15, 17), (12, 16, 20), (15, 20, 25), (7, 24, 25),
(10, 24, 26), (20, 21, 29)]
'''

def integers():             # Generate integers
    i = 1
    while True:
        yield i
        i += 1

def take(n, seq):           # Return the first n items in the sequence
    seq = iter(seq)
    tuple_list = []
    try:
        for num in range(n):
            tuple_list.append(next(seq))
    except StopIteration:
        pass
    return tuple_list

pyt = ((x,y,z)              # Generates pythagorean values
       for z in integers()
       for y in range(1,z)
       for x in range(1,y)
       if x*x + y*y == z*z)

print(take(10, pyt))        # Prints the pythagorean values

