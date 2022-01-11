// Ryan Long
// CS2060_001
// HW 3 Stacks
// Due October 25, 2018

/** Program Description:
* This program implements a stack with 5 int slots.
* Pointer artihmatic is used for everything.
* A local int pointer 'top' keeps track of the last int in the stack,
* No index/varibale is used to keep track of the top element
* in the stack except for the pointer.
*
* Note: I was unable to create an array of function pointers
* because I was not able to pass in top correctly.
* For the code to compile and run, I chose to
* use if/else statements to call the appropriate function.
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5 // sets number of elements in the stack

/** Prototypes */
void push(int newValue);
void pop(void);
void unwind(void);

/** Global variables */
int stack[SIZE] = {0};
int *top = 0;
int *pointer = 0;

/** main */
int main() {

// Allocate memory for stack
int *stack = malloc (sizeof(int) * SIZE);

/** Local Variables*/
int choice = 0;
int value = 0;
top = stack; // points to top of stack
pointer = stack; // pointer initialized


      /** Display welcome message */
    printf("Welcome to Ryan Long's Stack Creator!\n");
    printf("This program creates a stack with up to 5 integers.");

    do {

    /** Prompt user to choose a function to run */
    printf("\n\nChoose an option from the menu:\n\n");
    printf("0    exit (unwinds stack and terminates)\n");
    printf("1    push value onto stack\n");
    printf("2    pop value off stack\n\n");

    scanf("%d", &choice);

        if (choice == 1) {
            printf("\nEnter value to push onto stack: ");
            scanf("%d", &value);
            push(value);
        }

       else if (choice == 2) {
            pop();
        }

        else if (choice == 0) {
            unwind();
        }

        else {
            printf("\n%d is not a valid choice, try again.", choice);
        }

    } while (choice != 0); // loops safely, exits after termination message

    return 0;

} // main


/** push method pushes an integer of the user's choosing onto the stack.
*   If the stack is full, the user is informed.
*/
void push(int newValue) {
    if (top == (pointer + SIZE)) {
        printf("\nThe stack is full!\n");
    } else {
        *top = newValue;
        printf("\n%d pushed onto stack", *(top));
        top++;
    }
}


/** pop method pops an integer off of the stack.
*   If the stack is empty, the user is informed.
*/
void pop(void) {
    if (top == pointer) {
        printf("\nThe stack is empty!\n");
    } else {
        top--;
        printf("\n%d popped from stack", *(top));
    }
}


/** unwind method pops integers from the stack until the stack is empty.
*   Once the stack is empty, the user is informed and the program exits.
*/
void unwind(void) {
    while (top > pointer) {
        pop();
    }
    printf("\n\nAll values are popped from the stack.\n");
    printf("The program is terminated.  Goodbye!\n");
    exit(0);
}
