# Pygame - Click on an image and have it move randomly

# 1 -Import packages
import pygame
from pygame.locals import *
import sys
from pathlib import Path
import random

# 2- Define constants
BLACK = (0, 0, 0)
TEAL = (0, 128, 128)
WINDOW_WIDTH = 640
WINDOW_HEIGHT = 480
FPS = 30
BALL_WIDTH_HEIGHT = 100
MAX_WIDTH = WINDOW_WIDTH - BALL_WIDTH_HEIGHT
MAX_HEIGHT = WINDOW_HEIGHT - BALL_WIDTH_HEIGHT
BASE_PATH = Path(__file__).resolve().parent
pathToBall = str(BASE_PATH) + '\images\ball.png'

# 3 - Initialize the world
pygame.init()
window = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))
clock = pygame.time.Clock()

# 4 - Load assets (images, sounds, etc)
ballImage = pygame.image.load("images/ball.png")

# 5 - Init variables
ballX = random.randrange(MAX_WIDTH)
ballY = random.randrange(MAX_HEIGHT)
ballRect = pygame.Rect(ballX, ballY, BALL_WIDTH_HEIGHT, BALL_WIDTH_HEIGHT)

# 6 - Loop forever
while True:
    # 7 - Check for and handle events
    for event in pygame.event.get():
        # If close button is clicked, quit pygame and end program
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        # See if user clicked
        if event.type == pygame.MOUSEBUTTONUP:
            # Check if the mouse click is on the ball
            # If it is, choose a new random location
            if ballRect.collidepoint(event.pos):
                ballX = random.randrange(MAX_WIDTH)
                ballY = random.randrange(MAX_HEIGHT)
                ballRect = pygame.Rect(ballX, ballY, BALL_WIDTH_HEIGHT, BALL_WIDTH_HEIGHT)
                
        # 8 - Do any FPS actions

        # 9 - Clear the window
        window.fill(TEAL)

        # 10 - Draw all window elements
        # Draw ball at random location
        window.blit(ballImage, (ballX, ballY))

        # 11 - Update the window
        pygame.display.update()

        # 12 - Slow down
        clock.tick(FPS)
