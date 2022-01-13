# eggs adds 'Hello' to a list
def eggs(someParam):
    someParam.append('Hello')

spam = ['foo','bar']
print(spam)

eggs(spam)
print(spam)

