'''
Homework 6, Exercise 1
Decorators and Files
Ryan Long
11/10/2020

This program uses a decorator that will sleep for a certain number
of seconds before it calls the decorated function.

The program uses an optional rate arg that controls how long it sleeps,
using a default of 1 second.

The @slowDown example has been modified to accept the optional time argument.
'''

import functools
import time

def slowDown(func, rate=1):
    """Sleep n seconds before calling the function"""
    @functools.wraps(func)
    def wrapperSlowDown(*args, **kwargs):
        time.sleep(rate)
        return func(*args, **kwargs)
    return wrapperSlowDown

print("Count with sleep set to 3 seconds:")
@slowDown(slowDown, rate=3)

def countdown(fromNumber):
    if fromNumber < 1:
        print("Liftoff!")
    else:
        print(fromNumber)
        countdown(fromNumber - 1)

countdown(5)
# 5
# 4
# 3
# 2
# 1
# Liftoff!
