# This program walks a directory tree
import os

for folderName, subfolders, filenames in os.walk(r'C:\Users\Ryan\Desktop\Python'):
    print('The folder is ' + folderName)
    print('The subfolders in ' + folderName + ' are: ' + str(subfolders))
    print('The filenames in ' + folderName + ' are: ' + str(filenames))
    print()

'''
    for file in filenames:
        if file.endswith('py'):
            shutil.copy(os.join(folderName, file), os.join(folderName, file + '.backup'))
'''
