# read and write files

#################
# Reading files #
#################

# open the file in read mode
helloFile = open(r'c:\users\ryan\Desktop\python\hello.txt')

# read the file, closing when finished (returns a single string)
content = helloFile.read()
print(content)
helloFile.close()

# Alternative: readlines returns a list of strings
helloFile = open(r'c:\users\ryan\Desktop\python\hello.txt')
print(helloFile.readlines())
helloFile.close()

#################
# Writing files #
#################

# overwrite (w) vs append (a)
helloFile = open(r'c:\users\ryan\Desktop\python\hello.txt', 'a')
helloFile.write('Hello!!!!\n')
helloFile.close()

# read the file, closing when finished (returns a single string)
helloFile = open(r'c:\users\ryan\Desktop\python\hello.txt')
content = helloFile.read()
print(content)
helloFile.close()

# The shelve module
# This allows you to store lists and dictionaries to a file and re-open them later
import shelve
shelfFile = shelve.open('mydata')
shelfFile['cats'] = ['Zophie', 'Pooka', 'Simon', 'Fat-tail', 'Cleo']
shelfFile.close()
shelfFile = shelve.open('mydata')
print(shelfFile['cats'])

list(shelfFile.keys())        # see keys 
list(shelfFile.values())      # see values

shelfFile.close()

