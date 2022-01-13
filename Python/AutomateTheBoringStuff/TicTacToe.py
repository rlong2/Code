#######################
# Tic-Tac-Toe Program #
#######################

import random, copy

def printBoard(board):
    # prints the given board to the screen
    print(board['top-L'] + '|' + board['top-M'] + '|' + board['top-R'])
    print('-----')
    print(board['mid-L'] + '|' + board['mid-M'] + '|' + board['mid-R'])
    print('-----')
    print(board['low-L'] + '|' + board['low-M'] + '|' + board['low-R'])

def inputPlayerLetter():
    # The player chooses to start as 'X' or 'O'
    letter = ''
    while not (letter == 'X' or letter == 'O'):
        print('Do you want to be X or O?')
        letter = input().upper()
    # Computer gets the other letter
    if letter == 'X':
        return ['X','O']
    else:
        return ['O','X']
    
def whoGoesFirst():
    # randomly choose who goes first
    if random.randint(0,1) == 0:
        return 'computer'
    else:
        return 'player'

def playAgain():
    # returns True if player wants to play again
    print('Do you want to play again? (yes or no)')
    return input().lower().startswith('y')

def makeMove(board, letter, move):
    board[move] = letter

def isWinner(bo, le):
    # Given the board and the player's letter, returns True if player has won,
    # ie there are 3 of the same number in a row, horizontally, vertically, or diagonally.
    # 'bo' is board and 'le' is letter so we don't have to type as much
    return((bo['top-L'] == le and bo['top-M'] == le and bo['top-R'] == le) or # across the top
    (bo['mid-L'] == le and bo['mid-M'] == le and bo['mid-R'] == le) or        # across the middle
    (bo['low-L'] == le and bo['low-M'] == le and bo['low-R'] == le) or        # across the bottom
    (bo['top-L'] == le and bo['mid-L'] == le and bo['low-L'] == le) or        # down the left side
    (bo['top-M'] == le and bo['mid-M'] == le and bo['low-M'] == le) or        # down the middle
    (bo['top-R'] == le and bo['mid-R'] == le and bo['low-R'] == le) or        # down the right side
    (bo['top-L'] == le and bo['mid-M'] == le and bo['low-R'] == le) or        # diagonally L to R
    (bo['top-R'] == le and bo['mid-M'] == le and bo['low-L'] == le))          # diagonally R to L

def isSpaceFree(board, move):
    # return True if the passed move is free on the passed board. Checks if move is playable
    return board[move] == ' '

def getPlayerMove(board):
    # Let player type in their move
    move = ' '
    while move not in 'top-L top-M top-R mid-L mid-M mid-R low-L low-M low-R'.split() or not isSpaceFree(board, move):
        print('What is your next move? (top-,mid-, low- & L, M, R)')
        move = input()
    return move

def chooseRandomMoveFromList(board, movesList):
    # returns a valid move from the passed list on the passed board
    # returns None if there is no valid move
    possibleMoves = []
    for i in movesList:
        if isSpaceFree(board, i):
            possibleMoves.append(i)

    if len(possibleMoves) != 0:
        return random.choice(possibleMoves)
    else:
        return None

def getComputerMove(board, computerLetter):
    # given a board and the computer's letter, determine where to move and return that move
    if computerLetter == 'X':
        playerLetter = 'O'
    else:
        playerLetter = 'X'

    # Tic-Tac-Toe AI Algorithm
    # First, check if we can win on the next move
    for i in 'top-L top-M top-R mid-L mid-M mid-R low-L low-M low-R'.split():
        dupe = copy.copy(board)
        if isSpaceFree(dupe, i):
            makeMove(dupe, playerLetter, i)
            if isWinner(dupe, playerLetter):
                return i

    # Try to take one of the corners if they are free
    move = chooseRandomMoveFromList(board, ['top-L', 'top-M', 'top-R'])
    if move != None:
        return move

    # Try to take center if it is free
    if isSpaceFree(board, 'mid-M'):
        return 'mid-M'

    # Move on one of the sides
    return chooseRandomMoveFromList(board, ['top-M', 'low-M', 'mid-L', 'mid-R'])

def isBoardFull(board):
    # return true if every space on the board has been taken
    for i in 'top-L top-M top-R mid-L mid-M mid-R low-L low-M low-R'.split():
        if isSpaceFree(board, i):
            return False
        return True
        
    
########
# main #
print('Welcome to Tic-Tac-Toe!')

wantToPlay = True

while wantToPlay == True:
    # reset the board
    theBoard = {'top-L':' ', 'top-M':' ', 'top-R':' ',
                'mid-L':' ', 'mid-M':' ', 'mid-R':' ',
                'low-L':' ', 'low-M':' ', 'low-R':' '}

    playerLetter, computerLetter = inputPlayerLetter()
    turn = whoGoesFirst()
    print('The ' + turn + ' will go first')

    print('Player letter is ' + playerLetter)
    print('Computer letter is ' + computerLetter)
    
    gameIsPlaying = True

    while gameIsPlaying:
        if turn == 'player':
            # Player's turn
            print('Player\'s turn')
            printBoard(theBoard)
            move = getPlayerMove(theBoard)
            makeMove(theBoard, playerLetter, move)

            if isWinner(theBoard, playerLetter):
                printBoard(theBoard)
                print('Nice, you won!')
                gameIsPlaying = False
            else:
                if isBoardFull(theBoard):
                    printBoard(theBoard)
                    print('The game is a tie!')
                    break
                else:
                    turn = 'computer'
        else:
            print('compter\'s turn')
            # Computer's turn
            move = getComputerMove(theBoard, computerLetter)
            makeMove(theBoard, computerLetter, move)

            if isWinner(theBoard, computerLetter):
                printBoard(theBoard)
                print('The computer won the game!')
                gameIsPlaying = False
            else:
                if isBoardFull(theBoard):
                    printBoard(theBoard)
                    print('The game is a tie!')
                    break
                else:
                    turn = 'player'
    print('Play again returns ' + str(playAgain()))
    if playAgain() == False:
        wantToPlay = False

