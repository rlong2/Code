foo = 0
while foo < 5:
    foo = foo + 1
    if foo == 3:
        continue    # jump back to while loop, print 'foo is n' is not called
    print('foo is ' + str(foo))
