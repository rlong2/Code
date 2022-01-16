'''
Program to click the mouse at a specific time

https://pypi.org/project/schedule/
https://pypi.org/project/mouse/
https://stackoverflow.com/questions/11523918/python-start-a-function-at-given-time
'''

import schedule, time, mouse, re

def MouseClick():
    print("Click!")
    mouse.click('left')

def Examples():
    print('''Enter the time you want mouse to click in a XX:XX or XX:XX:XX format.
Example: If you want 9 AM, enter 09:00
Example: If you want 1:20 PM + 40 seconds, enter 13:20:40
          ''')
    
# Main
Examples()
user_time = "1"
while not re.match("[0-2][0-9]:[0-9][0-9]", user_time):
    user_time = input("Time for mouse click: ")

print(f"Mouse set to click at {user_time}")           
schedule.every().day.at(user_time).do(MouseClick)

while True:
    schedule.run_pending()
    time.sleep(0.01)
