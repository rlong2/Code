spam = 42

def funk_1():
    spam = 10
    print('in funk_1, spam is ' + str(spam))

def funk_2():
    spam = 33
    print('in funk_2, spam is ' + str(spam))

print('in main, spam is ' + str(spam))
funk_1()
funk_2()

print('adding 5 to spam global')
spam = spam + 5

print('in main, spam is ' + str(spam))
funk_1()
funk_2()
