'''
To work out the love score between two people:
Take both people's names and check for the number of times the letters in the word TRUE occurs. 
Then check for the number of times the letters in the word LOVE occurs. 
Then combine these numbers to make a 2 digit number.
'''
# 🚨 Don't change the code below 👇
print("Welcome to the Love Calculator!")
name1 = input("What is your name? \n")
name2 = input("What is their name? \n")
# 🚨 Don't change the code above 👆

#Write your code below this line 👇
true_string = "True"
love_string = "Love"
true_score_1 = 0
love_score_1 = 0
true_score_2 = 0
love_score_2 = 0

for char in name1.upper():
    if char in true_string.upper():
        true_score_1 += 1
    if char in love_string.upper():
        love_score_1 += 1

for char in name2.upper():
    if char in true_string.upper():
        true_score_2 += 1
    if char in love_string.upper():
        love_score_2 += 1

total_true_score = true_score_1 + true_score_2
total_love_score = love_score_1 + love_score_2

combined_score = str(total_true_score) + str(total_love_score)
combined_score = int(combined_score)

# Create message
if combined_score < 10 or combined_score > 90:
    message = ", you go together like coke and mentos."
elif combined_score > 40 and combined_score < 50:
    message = ", you are alright together."
else:
    message = "."

print(f"Your score is {combined_score}{message}" )