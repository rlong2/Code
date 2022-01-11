import random

# ASCII art
Rock = '''
    _______
---'   ____)
      (_____)
      (_____)
      (____)
---.__(___)
'''

Paper = '''
    _______
---'   ____)____
          ______)
          _______)
         _______)
---.__________)
'''

Scissors = '''
    _______
---'   ____)____
          ______)
       __________)
      (____)
---.__(___)
'''

# Assign 0, 1, and 2 values
game_dict = {0 : Rock, 1 : Paper, 2 : Scissors}

# Prompt
choice = int(input(("What do you choose? Type 0 for Rock, 1 for Paper or 2 for Scissors.\n")))
computer_choice = random.randrange(0,2)

print(f"You chose: {game_dict.get(choice)}")
print(f"Computer chose: {game_dict.get(computer_choice)}")

# Determine winner
if game_dict.get(choice) == game_dict.get(computer_choice):
    print("Tie game!")
elif game_dict.get(choice) == Rock:
    if game_dict.get(computer_choice) == Scissors:
        print("Player wins!")
    else:
        print("Computer wins!")
elif game_dict.get(choice) == Paper:
    if game_dict.get(computer_choice) == Scissors:
        print("Computer wins!")
    else:
        print("Player wins!")
else:                               # Scissors
    if game_dict.get(computer_choice) == Rock:
        print("Computer wins!")
    else:
        print("Player wins!")
