# copying/moving folders

import shutil

# copy and rename a file
shutil.copy(r'C:\Users\Ryan\Desktop\Python\AutomateTheBoringStuff\hello.txt', r'c:\garlic\hello_copy.txt')

# copy a folder
shutil.copytree('C:\\Users\\Ryan\\Desktop\\Python\\AutomateTheBoringStuff\\testFolder', 'C:\\Users\\Ryan\\Desktop\\Python\\AutomateTheBoringStuff\\testFolder_BKP')

# move a folder
shutil.move(r'C:\Users\Ryan\Desktop\Python\AutomateTheBoringStuff\testFolder', r'c:\Garlic')
