import os


#os.path.join('folder1','folder2','folder3','file.png') # create file path w/ proper OS syntax for path name
#os.getcwd() # get current working directory
#os.chdir('c:\\') # change working directory to root
#os.path.abspath('spam.png') # gives absolute path for a file
#os.path.dirname('c:\\folder1\\folder2\\spam.png') # output directory, not file
#os.path.basename('c:\\folder1\\folder2\\spam.png') # output last file/folder in path 
#os.path.exists('c:\\folder1\\folder2\\spam.png') # does path exist? T/F
#os.path.isfile('foo.txt')
#os.path.isdir('foo')
#os.path.getsize(r'c:\windows\system32\calc.exe') # size in bytes
#os.listdir(r'C:\Users\Ryan\Desktop\Python') # list of files and folders in dir
#os.makedirs('foo') # make a directory


# Small program to get total size of files in a folder
totalSize = 0
myPath = 'C:\\Users\\Ryan\\Desktop\\Python'
for filename in os.listdir(myPath):
    if not os.path.isfile(os.path.join(myPath, filename)):
        continue
    totalSize = totalSize + os.path.getsize(os.path.join(myPath, filename))

print('Total size of files in ' + myPath + ' is ' + str(totalSize) + ' bytes.')
