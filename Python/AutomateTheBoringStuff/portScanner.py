# A simple port scanner via:
# https://www.crusec.com/single-post/2020/05/21/Building-A-Simple-Python-Port-Scanner

import socket
import re
from ipaddress import *


def GetTarget():
    # This function gets an ip address to scan
    ipRegex = re.compile(r'^[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}.[0-9]{1,3}$')
    print('Enter IP address to scan:')
    target = input()
    while re.match(ipRegex, target) is None: # prompt again if invalid input
        print('Invalid ip input, try again.')
        print('Enter IP address to scan:')
        target = input()
    return target

def GetPorts():
    # This function gets ports to scan
    print('\nWhat ports do you want to scan?'
          + '\n1: Common Ports (1-1024)'
          + '\n2: All Ports'
          + '\n3: Specific Ports'
          )
    portChoice = input()

    if portChoice == str(1):
        print('\nScanning common ports...')
        ports = range(1,1025)
        return ports
    elif portChoice == str(2):
        print('\nScanning all ports...')
        ports = range(1,65536)
        return ports
    elif portChoice == str(3):
        print('\nWhich specific ports do you want to scan?') # load user ports into a list
        print('Enter the ports you want to scan, seperated by commas:')
        ports = input().split(',')
        portList = []
        for i in ports:
            port = int(i)
            portList.append(port)
        return portList
    else:
        print('Invalid input. Try again')
        GetPorts()

def Scan():
    # This function scans the specified ports
    socket.setdefaulttimeout(.01)
    target = str(GetTarget())
    ports = GetPorts()
    foundOpenPorts = False
    try:
        for i in ports:
            conn_skt = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
            result = conn_skt.connect_ex((target, i))
            if result == 0:
                print('[+]tcp %s is open on host %s' % (i, target))
                foundOpenPorts = True
                conn_skt.close()
            #else:
                #print('[-]tcp %s is closed on host %s' % (i, target))
        if foundOpenPorts == False:
            print('No open ports found! Try adjusting socket.setdefaulttimeout if you think there are ports open.\n')
    
    except socket.error as error:
                pass
# main
scanAgain = 'y'

while(scanAgain.lower().startswith('y')):
      Scan()
      print('\nScan another IP? (Y/N):')
      scanAgain = input()
print('Thanks for using the program!')
