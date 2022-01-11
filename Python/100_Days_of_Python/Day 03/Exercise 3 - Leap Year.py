'''
This is how you work out whether if a particular year is a leap year.
    on every year that is evenly divisible by 4 
    **except** every year that is evenly divisible by 100 
    **unless** the year is also evenly divisible by 400
'''
# 🚨 Don't change the code below 👇
year = int(input("Which year do you want to check? "))
# 🚨 Don't change the code above 👆

#Write your code below this line 👇
leap_year = False
if year % 4 == 0:
    leap_year = True
    if year % 100 == 0:
        leap_year = False
        if year % 400 == 0:
            leap_year = True
    
if leap_year:
    print("Leap year.")
else:
    print("Not leap year.") 