'''
Lost in a maze

Reeborg was exploring a dark maze and the battery in its flashlight ran out.

Write a program using an if/elif/else statement so Reeborg can find the exit.
The secret is to have Reeborg follow along the right edge of the maze,
turning right if it can, going straight ahead if it can’t turn right,
or turning left as a last resort.

What you need to know

    The functions move() and turn_left().
    Either the test front_is_clear() or wall_in_front(), right_is_clear() or wall_on_right(), and at_goal().
    How to use a while loop and if/elif/else statements.
    It might be useful to know how to use the negation of a test (not in Python).

Goal to achieve:
The final position of the robot must be (x, y) = (6, 4)

'''

def turn_right():
    turn_left()
    turn_left()
    turn_left()

while not at_goal():
    # Follow around the right edge of the maze 
    while front_is_clear() and not at_goal():
        if right_is_clear():
            if not at_goal():
                turn_right()
                move()
        else:
            move() 
    # Last Resort: Turn left
    else:
        if right_is_clear():
            turn_right()
            if at_goal():
                break
            else:
                move()
