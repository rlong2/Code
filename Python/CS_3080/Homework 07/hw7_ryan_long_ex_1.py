'''
Homework 7, Exercise 1
Renaming Files with American-Style Dates to Asian-Style Dates
Ryan Long
11/23/2020

This program searches all filenames in the current working directory
and changes date format MM-DD-YYYY to YYYY-MM-DD

'''

import re, os, shutil

for filename in os.listdir('.'):

    # Substitute                   MM-DD-YYYY   to    YYYY-MM-DD
    newFilename = re.sub(r'(\d{2})-(\d{2})-(\d{4})', '\\3-\\1-\\2', filename)

    if filename == newFilename:
        continue
    else:
        print(filename + " --> " + newFilename)
        shutil.move(filename, newFilename)
