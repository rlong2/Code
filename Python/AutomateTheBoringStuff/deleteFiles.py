# This program removes files in the directory that start with mydata
# you need the send2trash module
import os
import send2trash

os.chdir(r'C:\Users\Ryan\Desktop\Python\AutomateTheBoringStuff')

for filename in os.listdir():
    if filename.startswith('mydata'):
        # os.unlink(filename) # dangerous, deletes permanently
        send2trash.send2trash(filename)
        print(filename) # see files (dry run)
