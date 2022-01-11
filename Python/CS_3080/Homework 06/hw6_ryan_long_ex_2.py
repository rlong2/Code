'''
Homework 6, Exercise 2
Fibonacci sequence
Ryan Long
11/10/2020

This program calculates a Fibonacci sequence following this criteria:
1) Use an @cache decorator that will save the calculations in a function
attribute dictionary. Make the decorator work for functions with more than 1 arg.
2) Apply the @countCalls decorator introduced in class.

Using cache make a HUGE difference in function calls because
when cache is used, the fibonacci function doesn't have to recalculate
numbers that it has already calculated:

fibonacci(35) = 9227465
With cache:    Took 69 calls (less than 1 second total runtime)
Without cache: Took 29,860,703 calls (5+ minutes total runtime)

fibonacci(42) = 267914296
With cache:    Took 83 calls (less than 1 second total runtime)
Without cache: Took 866,988,873 calls (15+ minutes total runtime)

fibonacci(50) = 12586269025
With cache:    Took 99 calls (less than 1 second total runtime)
Without cache: Took 40,730,022,147 calls (4+ hours total runtime)

'''

import functools

def countCalls(func):
    @functools.wraps(func)
    def wrapperCountCalls(*args, **kwargs):
        wrapperCountCalls.numCalls += 1
        return func(*args, **kwargs)
    wrapperCountCalls.numCalls = 0
    return wrapperCountCalls

def cache(func):
    CacheDict = {}
    @functools.wraps(func)
    def wrapperCache(*args, **kwargs):
        val = args + tuple(kwargs.items())
        if val not in wrapperCache.cache:
            wrapperCache.cache[val] = func(*args, **kwargs)
        return wrapperCache.cache[val]
    wrapperCache.cache = CacheDict
    return wrapperCache

@countCalls
@cache

def fibonacci(num):
    if num < 2:
        return num
    return fibonacci(num - 1) + fibonacci(num - 2)

num = 10
print("fibonacci(" + str(num) + ") = " + str(fibonacci(num)))
print("Took " + str(fibonacci.numCalls) + " calls")
