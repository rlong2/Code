'''
You have access to a database of student_scores in the format of a dictionary. 
The keys in student_scores are the names of the students and the values are their exam scores.

Write a program that converts their scores to grades. 
By the end of your program, you should have a new dictionary called student_grades 
that should contain student names for keys and their grades for values. 
The final version of the student_grades dictionary will be checked.
'''

student_scores = {
  "Harry": 81,
  "Ron": 78,
  "Hermione": 99, 
  "Draco": 74,
  "Neville": 62,
}
# 🚨 Don't change the code above 👆

# Create an empty dictionary called student_grades.
student_grades = {}

# Write your code below to add the grades to student_grades.👇
# Fill the student_grades dictionary
# Change numberical scores to text strings
student_grades = student_scores
for key in student_grades:
    value = student_grades[key]
    if value >= 91:
        value = "Outstanding"
    elif value >= 81:
        value = "Exceeds Expectations"
    elif value >= 71:
        value = "Acceptable"
    else:
        value = "Fail"
    
    student_grades[key] = value
    
# 🚨 Don't change the code below 👇
print(student_grades)
