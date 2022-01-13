# This function has a bug, which shall be logged
import logging

# Comment line below to disable logging
#logging.basicConfig(level=logging.DEBUG, format='%(asctime)s - %(levelname)s- %(message)s')

# to write to file instead of screen:
logging.basicConfig(filename = 'programLog.txt', level=logging.DEBUG, format='%(asctime)s - %(levelname)s- %(message)s')

# Comment out line below to disable logging messages
#logging.disable(logging.CRITICAL)

logging.debug('Start of program')

def factorial(n):
    logging.debug('Start of factorial %s' % (n))
    total = 1
    for i in range(1, n+1):
        total *= i
        logging.info('i is %s, total is %s' % (i, total))
    logging.debug('Return value is %s' % (total))
    return total

print(factorial(5))

logging.debug('End of program')
