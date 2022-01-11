'''
## Tip Calculator
# Instructions
If the bill was $150.00, split between 5 people, with 12% tip. 
Each person should pay (150.00 / 5) * 1.12 = 33.6
Format the result to 2 decimal places = 33.60
Thus everyone's share of the total bill is $30.00 plus a $3.60 tip.
'''
#Write your code below this line 👇

print("Welcome to the tip calculator.")
total_bill = input("What was the total bill? $")
tip_percentage = input("What percentage tip would you like to give? 10, 12, or 15? ")
people_splitting = input("How many people to split the bill? ")
single_payment = float(total_bill) / int(people_splitting)
single_tip = single_payment * (float(tip_percentage) / 100) 
person_pays = single_payment + single_tip
person_pays_rounded = round(person_pays,2)
print(f"Each person should pay: ${person_pays_rounded}")