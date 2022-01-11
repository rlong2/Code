'''
Homework 7, Exercise 2
Selective Copy
Ryan Long
11/27/2020

This program:
1) Walks through a directory tree (os.walk()) and searches for PDFs
2) Prints each PDF's absolute path and file size
3) Copies these files into a new folder
'''

import os
import shutil

if not os.path.exists('copied_pdfs'):
    os.makedirs('copied_pdfs')
    print("Created a copied_pdfs directory")

for folderName, subfolders, filenames in os.walk(os.path.abspath('.')):
    for filename in filenames:

        # Don't recurse into the copied_pdfs directory
        if folderName.endswith("copied_pdfs"):
            continue

        # If file has a .pdf extension, copy it
        elif filename.endswith(".pdf"):
            kb = os.path.getsize(filename) / 1024
            print(os.path.join(folderName, filename) +
                  "\t" + str(kb) + " Kilobytes")
            
            shutil.copy(filename, 'copied_pdfs')

print("\nCopied the PDFs listed above to local copied_pdfs directory")
            
