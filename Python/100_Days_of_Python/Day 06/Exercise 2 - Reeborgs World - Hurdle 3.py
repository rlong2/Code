'''
Reeborg's World
Hurdles race with varying lengths between hurdles
Reeborg has entered a hurdles race.
Make him run the course, following the path shown.

More advanced:
You may have noticed that your solution has some repeated patterns.
If you know how to define functions, define a function named jump()
and use it to simplify your program.

Goal to achieve:
The final position of the robot must be (x, y) = (13, 1)

https://reeborg.ca/reeborg.html?lang=en&mode=python&menu=worlds%2Fmenus%2Freeborg_intro_en.json&name=Hurdle%201&url=worlds%2Ftutorial_en%2Fhurdle1.json
'''

def turn_right():
    turn_left()
    turn_left()
    turn_left()

def jump():
    turn_left()
    move()
    turn_right()
    move()
    turn_right()
    move()
    turn_left()

while not at_goal():
    if front_is_clear():
        move()
    else:
        jump()
