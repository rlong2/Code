# Pygame - Display a ball

# 1 -Import packages
import pygame
from pygame.locals import *
import sys
from pathlib import Path

# 2- Define constants
BLACK = (0, 0, 0)
TEAL = (0, 128, 128)
WINDOW_WIDTH = 640
WINDOW_HEIGHT = 480
FPS = 30
BASE_PATH = Path(__file__).resolve().parent
pathToBall = str(BASE_PATH) + '\images\ball.png'

# 3 - Initialize the world
pygame.init()
window = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))
clock = pygame.time.Clock()

# 4 - Load assets (images, sounds, etc)
ballImage = pygame.image.load("images/ball.png")

# 5 - Init variables

# 6 - Loop forever
while True:
    # 7 - Check for and handle events
    for event in pygame.event.get():
        # If close button is clicked, quit pygame and end program
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        # 8 - Do any FPS actions

        # 9 - Clear the window
        window.fill(TEAL)

        # 10 - Draw all window elements
        window.blit(ballImage, (100, 200))

        # 11 - Update the window
        pygame.display.update()

        # 12 - Slow down
        clock.tick(FPS)
