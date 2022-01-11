'''
Homework 5, Exercise 1
Iterators and Generators
Ryan Long
10/26/2020

This program taks a list and iterates it from the reverse direction
'''

class ReverseIter:

    def __init__(self, list):
        self.list= list
        self.length = len(self.list)

    def __iter__(self):
        return self

    def __next__(self):
        if (self.length > 0):
            print(self.list[self.length - 1])
            self.length -= 1
        else:
            raise StopIteration()

# Call function repeatedly
my_list = ReverseIter([1,2,3,4])
next(my_list)                       # 4
next(my_list)                       # 3
next(my_list)                       # 2
next(my_list)                       # 1
next(my_list)                       # Error: StopIteration
