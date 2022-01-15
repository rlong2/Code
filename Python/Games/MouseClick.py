'''
Program to click the mouse at a specific time

https://pypi.org/project/schedule/
https://pypi.org/project/mouse/
https://stackoverflow.com/questions/11523918/python-start-a-function-at-given-time
'''

import schedule, time, mouse

def MouseClick():
    print("Click!")
    mouse.click('left')

# Main
#schedule.every(10).seconds.do(MouseClick)
schedule.every().day.at("13:44").do(MouseClick)

while True:
    schedule.run_pending()
    time.sleep(0.01)
