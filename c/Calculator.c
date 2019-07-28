// Ryan Long
// CS2060_001
// HW 2 Calculator
// Due October 4, 2018

/** Program Description:
* This program will prompt the user to choose the function they want to run.
* The program will loop, allowing the user to choose different functions
* that will either double, square, or cube an integer of their choosing.
* A single line of code will call the chosen function from an array of function pointers.
* The program will loop until the user enters '0'.
*/

#include <stdio.h>
#include <stdlib.h>

/** Prototypes */
double doubleFun(number);
double squareFun(number);
double cubeFun(number);


/** Main */
double main()
{

    double number;
    double functionChoice = 0;
    int returnedFunction = 0;

    //create and initialize an array of function pointers
    double(* functionPtr[3])(double)={doubleFun, squareFun, cubeFun};

    /** Display welcome message */
    printf(" ------------------------------------\n");
    printf("| Welcome to Ryan Long's Calculator! |\n");
    printf(" ------------------------------------\n");
    printf("This program takes a user-provided number \n");
    printf("and performs a calculation of your choosing.\n");
    printf("This program will loop until you choose to exit.\n");

    do { // This do-while loop goes through the menu at least once

    /** Prompt user to choose a function to run */
    printf("\nChoose an option from the menu: \n\n");

    printf("0\texit the program\n");
    printf("1\tdouble your number\n");
    printf("2\tsquare your number\n");
    printf("3\tcube your number\n\n");

    scanf("%f", &functionChoice);

     if (functionChoice == 0) {
      printf("\nProgram terminated.  Goodbye!\n");
      exit(0);
      }

      else if (functionChoice < 0 || functionChoice > 3) {
      printf("%f was not a valid choice\n", functionChoice);
            do {
                printf("\nYou can only pick 0, 1, 2, or 3: ");
                scanf("%f", &functionChoice);
            }

            while (functionChoice < 0 || functionChoice > 3);
                    if (functionChoice == 0) {
                        printf("\nProgram terminated.  Goodbye!\n");
                        exit(0);
                    }
      }

    printf("\nEnter a number to perform the calculation on: ");
    scanf("%f", &number);

     if (functionChoice > 0 && functionChoice < 4){
         returnedFunction =(*functionPtr[functionChoice - 1])(number); // returns called function
         printf("%d\n\n", returnedFunction);
      }

} // end first 'do'

while (functionChoice != 0); // while functionChoice is not 0, continue looping

} // end main method


// Doubling function doubleFun:
// This function will double the user's chosen number

double doubleFun (double number) {
    printf("\nYour doubled number is ");
    return (number * 2.0);
}


// Squaring function squareFun:
//This function will square the user's chosen number

double squareFun (double number) {
    printf("\nYour squared number is ");
    return (number * number);
}


// Cubing function cubeFun:
// This function will cube the user's chosen number

double cubeFun (double number) {
    printf("\nYour cubed number is ");
    return (number * number * number);
}


