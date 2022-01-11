'''
Homework 3, Exercise 4
Tic-Tac-Toe
Ryan Long
9/22/2020

This program fills a tic-tac-toe board and allows players to enter 'X' or 'O'
'''

def promptPlayer(player, turns):
    choice = int(input("\n" + player + ", enter location to play: "))

    if player == "Player One":
        token = 'X'
    else:
        token = 'O'
        
    play_token(board, choice, token)
    printBoard(board)

def play_token(board, location, token):
    if location < 1 or location > 9:
        print("You can't play outside the bounds!")
        choice = int(input("Enter location to play: "))
        play_token(board, choice, token)
    elif board[location] == "#":
        board[location] = token
    else:
        print("You can't overwrite a move!")
        choice = int(input("Enter location to play: "))
        play_token(board, choice, token)
    
def printBoard(board):
    i = 0
    for key, value in board.items():
        print("{}".format(value), end = " ")
        i += 1
        if i == 3 or i == 6:
            print()


# main
print("Welcome to Tic-Tac_Toe!")
print("Players can enter 1-9 for choices to play.")

# Create an empty board and populate it with 'blanks', represented by
# hashtags for greater user readability
board = {}
for i in range(1,10):
    board[i] = '#'

turns = 0

while True:
    promptPlayer("Player One", turns)
    turns += 1
    if turns == 9:
        break
    promptPlayer("Player Two", turns)
    turns += 1
print("\n\nThanks for playing!")

input("\nPress Enter to exit")
