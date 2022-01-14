'''
The Birthday Paradox
This program performs several probability experiments
to show the probability that even in a small group of people,
two people have a very high chance of sharing the same birthday.

https://en.wikipedia.org/wiki/Birthday_problem
'''

import datetime, random

# Returns a list of number random date objects for birthdays
def getBirthdays(numberOfBirthdays):
    birthdays = []
    for i in range(numberOfBirthdays):
        startOfYear = datetime.date(2001, 1, 1)

        # Get random day into year
        randomNumberOfDays = datetime.timedelta(random.randint(0, 364))
        birthday = startOfYear + randomNumberOfDays
        birthdays.append(birthday)
    return birthdays
    
MAX_BIRTHDAYS = 100

# Display introduction
print('''

The Birthday Paradox shows us that in a group of N people, the odds
that two of them have matching birthdays is surprisingly large.
This program foes a Monte Carlo simulation (repeated random simulations)
to explore this concept.

''')

# Create a tuple of months
MONTHS = ('Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun',
          'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec')

while True: # Loop until user enters valid guess
    print(f"How many birthdays shall I generate? (Max {MAX_BIRTHDAYS})")
    response = input("> ")
    if response.isdecimal() and (0 < int(response) <= MAX_BIRTHDAYS):
        numBDays = int(response)
        break # User entered valid amount
print()
