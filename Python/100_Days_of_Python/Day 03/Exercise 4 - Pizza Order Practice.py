'''
Congratulations, you've got a job at Python Pizza. Your first job is to build an automatic pizza order program.
Based on a user's order, work out their final bill.
Small Pizza: $15
Medium Pizza: $20
Large Pizza: $25
Pepperoni for Small Pizza: +$2
Pepperoni for Medium or Large Pizza: +$3
Extra cheese for any size pizza: + $1
'''
# 🚨 Don't change the code below 👇
print("Welcome to Python Pizza Deliveries!")
size = input("What size pizza do you want? S, M, or L ")
add_pepperoni = input("Do you want pepperoni? Y or N ")
extra_cheese = input("Do you want extra cheese? Y or N ")
# 🚨 Don't change the code above 👆

#Write your code below this line 👇
price = 0
if size.upper() == 'S':
    price += 15
elif size.upper() == 'M':
    price += 20
else:
    price += 25

if add_pepperoni.upper() == 'Y':
    if size.upper() == 'S':
        price += 2
    else:
        price += 3

if extra_cheese.upper() == 'Y':
    price += 1

print(f"Your final bill is: ${price}")
