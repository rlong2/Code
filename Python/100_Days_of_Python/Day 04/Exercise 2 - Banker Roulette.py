'''
You are going to write a program that will select a random name from a list of names. The person selected will have to pay for everybody's food bill.
Important: You are not allowed to use the choice() function.
'''
import random
# 🚨 Don't change the code below 👇
test_seed = int(input("Create a seed number: "))
random.seed(test_seed)

# Split string method
names_string = input("Give me everybody's names, separated by a comma. ")
names = names_string.split(", ")
# 🚨 Don't change the code above 👆

#Write your code below this line 👇
total_names = len(names)
random_index = random.randrange(total_names)
random_name = names[random_index]
print(f"{random_name} is going to buy the meal today!")