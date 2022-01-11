'''
You are going to write a program that calculates the average student height from a List of heights.
e.g. student_heights = [180, 124, 165, 173, 189, 169, 146]
The average height can be calculated by adding all the heights together and dividing by the total number of heights.
Important You should not use the sum() or len() functions in your answer. You should try to replicate their functionality using what you have learnt about for loops.
'''
# 🚨 Don't change the code below 👇
student_heights = input("Input a list of student heights ").split()
for n in range(0, len(student_heights)):
  student_heights[n] = int(student_heights[n])
# 🚨 Don't change the code above 👆

#Write your code below this row 👇
# Add heights
total_heights = 0
num_students = 0
for heights in student_heights:
    total_heights += heights
    num_students += 1

# Calculate average height
average_height = round(total_heights / num_students)

# Print results
print(f"total height = {total_heights}")
print(f"number of students = {num_students}")
print(average_height)
