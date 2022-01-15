'''
Program to click the mouse at a specific time
https://pypi.org/project/schedule/
https://pypi.org/project/mouse/
https://stackoverflow.com/questions/11523918/python-start-a-function-at-given-time
'''

import schedule
import time
import mouse

def job():
    print("Wello world!")

# Main
#schedule.every(10).seconds.do(job)
schedule.every().day.at("13:35").do(job)

while True:
    schedule.run_pending()
    time.sleep(0.01)
