// Ryan Long
// CS2060_001
// HW 5 Array of String Pointers
// Due November 20, 2018

/** This program creates and initializes an array of strings.
* The array is printed by running the array through a 'for' loop,
* moving from one pointer to the next.  The content is then sorted
* in alphabetical order from A-Z using a bubble sort and the
* sorted array is printed for the user.
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

/** Prototypes */
void printList(char * wordPtr[]);
void sortList(char * wordPtr[]);


/** main */
int main()
{
    printf("Welcome to Ryan Long's Sorting Program!\n\n"
           "An array of string pointers is created,\n"
           "printed, sorted, and re-printed.\n\n");

    char *wordPtr[] = {
                            "Stallman",
                            "Dogecoin",
                            "Vulpix",
                            "Mitnick",
                            "Zapdos",
                            "Bojack",
                            "Pikachu",
                            "Turing",
                            "Wigglytuff",
                            "Ritchie"
                        };


    printf(" -----------------\n");
    printf("| Unsorted names: |\n");
    printf(" -----------------\n");
    printList(wordPtr);
    printf("\n");

    sortList(wordPtr);

    printf("\n ---------------");
    printf("\n| Sorted names: |\n");
    printf(" ---------------\n");

    printList(wordPtr);

    return 0;

} // main


/** printList function prints the contents of the array
* by moving the pointer in a 'for' loop.
*/
void printList(char * wordPtr[]) {

    for(int count = 0; count < SIZE; count++) {
    printf("%s\n", wordPtr[count]);
    }
}


/** sortList sorts the contents of the array
* using a bubble sort.  The string's ASCII values
* are compared and sorted alphabetically from A-Z.
*/
void sortList(char * wordPtr[]) {

    int i = 0;
    int j = 0;
    char *temp = NULL;

    for(i = 1; i < SIZE; i++) {

        for(j = 0; j < (SIZE - i); j++) {

            if(*wordPtr[j] > *wordPtr[j+1]) {

                temp = wordPtr[j];
                wordPtr[j] = wordPtr[j+1];
                wordPtr[j+1] = temp;

            }
        }
    }

} // sortList
