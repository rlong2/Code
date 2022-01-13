# Adding 0 to 100 in for loop
total = 0
for i in range(101):
    total = total + i
print('total is ' + str(total))

# Adding 0 to 100 in while loop
total = 0
i = 0
while i<=100:
    total = total + i
    i = i + 1
print('total is ' + str(total))

print('\nMy name is ')
for i in range (11, 16): # start at 11, goes up to but does NOT include 16
    print('Larry ' + str(i))

print('\nMy other name is ')
for i in range (0, 100, 20): # count in increments of 20 from 0 to 100, not incl 100
    print('Jinx ' + str(i))

print('\nCounting down...')
for i in range(5, -1, -1):
    print(i)
