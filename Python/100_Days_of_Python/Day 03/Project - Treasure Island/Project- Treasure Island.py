print('''
*******************************************************************************
          |                   |                  |                     |
 _________|________________.=""_;=.______________|_____________________|_______
|                   |  ,-"_,=""     `"=.|                  |
|___________________|__"=._o`"-._        `"=.______________|___________________
          |                `"=._o`"=._      _`"=._                     |
 _________|_____________________:=._o "=._."_.-="'"=.__________________|_______
|                   |    __.--" , ; `"=._o." ,-"""-._ ".   |
|___________________|_._"  ,. .` ` `` ,  `"-._"-._   ". '__|___________________
          |           |o`"=._` , "` `; .". ,  "-._"-._; ;              |
 _________|___________| ;`-.o`"=._; ." ` '`."\` . "-._ /_______________|_______
|                   | |o;    `"-.o`"=._``  '` " ,__.--o;   |
|___________________|_| ;     (#) `-.o `"=.`_.--"_o.-; ;___|___________________
____/______/______/___|o;._    "      `".o|o_.--"    ;o;____/______/______/____
/______/______/______/_"=._o--._        ; | ;        ; ;/______/______/______/_
____/______/______/______/__"=._o--._   ;o|o;     _._;o;____/______/______/____
/______/______/______/______/____"=._o._; | ;_.--"o.--"_/______/______/______/_
____/______/______/______/______/_____"=.o|o_.--""___/______/______/______/____
/______/______/______/______/______/______/______/______/______/______/_____ /
*******************************************************************************
''')
print("Welcome to Treasure Island.")
print("Your mission is to find the treasure.") 

#https://www.draw.io/?lightbox=1&highlight=0000ff&edit=_blank&layers=1&nav=1&title=Treasure%20Island%20Conditional.drawio#Uhttps%3A%2F%2Fdrive.google.com%2Fuc%3Fid%3D1oDe4ehjWZipYRsVfeAx2HyB7LCQ8_Fvi%26export%3Ddownload

#Write your code below this line 👇
import random

while True:
    print("Two paths diverge. Do you go left or right? ")       # Left or right?
    left_or_right = input()

    if left_or_right.lower() == "left":
        print('''You turned left.
    A riverfull of alligators grin at you, licking their chops.
    Do you pet the alligators or leap over the river? (pet or leap)? ''')   # Pet alligators or lea over river?
        alligator_choice = input()
        if alligator_choice.lower().startswith("p"):
            print("The alligators are soothed. They share their treasure with you!")
        else:
            print("You try to jump the river and an alligator chomps you out of the air! You dead!")
    elif left_or_right.lower() == "right":
        print("You turned right, only to fall down a cliff to your death!")
    else:
        print("You entered a wormhole!")        # In a wormhole
        rand_num = random.randrange(0,10)
        guess = input("Guess the number to escape: ")
        while guess != str(rand_num):
            guess = input("Wrong! Guess the number to escape: ")
        print("Correct! You escape from the wormhole with the ultimate treasure!")

    play_again = input("Play again? yes/no: ")
    if play_again.lower().startswith("y"):
        continue
    else:
        break
