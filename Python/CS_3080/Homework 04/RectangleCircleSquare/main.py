'''
Homework 4, Exercise 2
Rectangle, Circle, and Square
Ryan Long
10/13/2020

This program has 3 classes: Rectangle, Circle, and Square
that use inheritance as much as possible
to perform a calculation.
All classes have methods that compute the area, diagonal, and perimeter.
The classes are used to calculate:
    The perimeter of a circle with a radius that's the half
    of the diagonal of a rectangle with a length 20 and width 10.
'''

from math import sqrt
from math import pi

class Rectangle():                          # Rectangle class
    def __init__(self, l, w):
        self.length = l
        self.width = w
    def area(self):                         # area of rectangle
        return self.length * self.width
    def perimeter(self):                    # perimeter of rectangle
        return 2 * self.length * self.width
    def diagonal(self):                     # diagonal of rectangle
        return float(sqrt(self.length**2 + self.width**2))

# Square class
# Square is a subset of Rectangle
class Square(Rectangle):
    def __init__(self, l):
        super().__init__(l)
    def area(self):
        return self.length * self.length
    def perimeter(self):
        return 4 * self.length
    def diagonal(self):
        return sqrt(2) * self.length

class Circle():
    def __init__(self, r):
        self.radius = r
    def area(self):
        return self.radius**2 * pi
    def perimeter(self):
        return 2 * self.radius * pi

class Square(Rectangle):
    def __init__(self, len):
        self.length = len
    def area_square(selfself):
        return len * len

# Rectangle with length 20, width 10
Rect1 = Rectangle(20, 10)
RectDiag = Rect1.diagonal()

# Creating a circle with radius that's half of the rectangle diagonal
Circle1 = Circle(RectDiag / 2)
print(Circle1.perimeter())
