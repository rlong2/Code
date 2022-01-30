############### Our Blackjack House Rules #####################

## The deck is unlimited in size. 
## There are no jokers. 
## The Jack/Queen/King all count as 10.
## The the Ace can count as 11 or 1.
## Use the following list as the deck of cards:
## cards = [11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10]
## The cards in the list have equal probability of being drawn.
## Cards are not removed from the deck as they are drawn.
## The computer is the dealer.

import random

# Returns a random card from the deck
def deal_card():
    cards = [11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10]
    random_card = random.choice(cards)
    return random_card

# Returns the score of the hand
def calculate_score(cards):
    total = 0
    for card in cards:
        total += card

    # If total exceeds 21 and there is an Ace, count it as 1 instead of 11
    #if total > 21 and 11 in cards:
        
    return total

# Main
play_again = input("Do you want to play a game of Blackjack? y/n: ").lower()
if play_again.startswith('y'):
    user_cards = [11, 6]
    computer_cards = [11, 8]
    #for card in range(2):
    #    user_cards.append(deal_card())
    #    computer_cards.append(deal_card())
    print(user_cards)
    print(computer_cards)
 
    user_score = calculate_score(user_cards)
    computer_score = calculate_score(computer_cards)
    print(f"user score is {user_score}")
    print(f"computer score is {_score}")
else:
    print("Thanks for playing!")
    
