# This script will mount and unmount a drive on a Raspberry Pi via a button push.
# It assumes an external hard drive is mounted via /etc/fstab
#

import os
import time
import RPi.GPIO as GPIO # Import Raspberry Pi GPIO library

def mount_drive():
    command = "sudo mount -a"
    return command

def view_mounted_drive():
    command = "df -h | grep mnt"
    return command

def button_callback(channel):
    print("Mounting drive...")
    os.system("date")
    os.system(mount_drive())
    os.system(view_mounted_drive())

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(10, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

GPIO.add_event_detect(10,GPIO.RISING,callback=button_callback)
message = input("Press button to mount drive. Press enter to quit\n\n")
