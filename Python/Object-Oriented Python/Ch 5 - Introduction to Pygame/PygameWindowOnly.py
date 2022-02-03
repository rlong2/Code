# Pygame - Open a window

# Import packages
import pygame
from pygame.locals import *
import sys

# Define constants
BLACK = (0, 0, 0)
TEAL = (0, 128, 128)
WINDOW_WIDTH = 640
WINDOW_HEIGHT = 480
FPS = 30

# Initialize the world
pygame.init()
window = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))
clock = pygame.time.Clock()

# Load assets (images, sounds, etc)

# Init variables

# Loop forever
while True:
    # Check for and handle events
    for event in pygame.event.get():
        # If close button is clicked, quit pygame and end program
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        # Do any FPS actions

        # Clear the window
        window.fill(TEAL)

        # Draw all window elements

        # Update the window
        pygame.display.update()

        # Slow down
        clock.tick(FPS)
