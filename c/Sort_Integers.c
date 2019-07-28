// Ryan Long
// CS2060_001
// HW 1 Pass by Reference Sort
// Due September 20, 2018

/** Program Description:
* This program asks the user for three integers.
* These values are printed on screen and labeled with their variable names.
* The values are passed by reference to a function that sorts them.
* These sorted values are printed on screen and labeled with their variable names.
*/

#include <stdio.h>

/** Prototype */
void sortByReference(int  *value1Ptr, int *value2Ptr, int *value3Ptr);

/** Main */
int main()
{
    int value1;
    int value2;
    int value3;

    int *value1Ptr = NULL;
    int *value2Ptr = NULL;
    int *value3Ptr = NULL;

    value1Ptr = &value1; /** value1Ptr is now the address of value1 */
    value2Ptr = &value2; /** value2Ptr is now the address of value2 */
    value3Ptr = &value3; /** value3Ptr is now the address of value3 */

// Display function addresses
printf("address of main is %p\n", main);
printf("address of sortByReference is %p\n\n", sortByReference);

    /** Display welcome message*/
    puts("Welcome to Ryan Long's Sort Program!");
    puts("This program will sort 3 user inputted integer values.\n");

    /** Prompt user for 3 integers */
    printf("Enter 3 whole numbers separated by spaces: ");
    scanf("%d %d %d", &value1, &value2, &value3);

    /** Display 3 unsorted integers */
    puts("\nThe three values to be sorted are: ");
    printf("value 1 = %d\t value 2 = %d\t value 3 = %d\n", *value1Ptr, *value2Ptr, *value3Ptr);

    /** call sort function */
    sortByReference(&value1, &value2, &value3);

    /** Display 3 sorted integers */
    puts("\nThe three sorted values are: ");
    printf("value 1 = %d\t value 2 = %d\t value 3 = %d\n", *value1Ptr, *value2Ptr, *value3Ptr);

    return 0;

} // end main method


/** Sort method:
* This method is passed the user's inputted values by reference.
* The references are sorted using 'if' statements.
* No code is returned from this method.
*/

void sortByReference(int  *value1Ptr, int *value2Ptr, int *value3Ptr)
{
    if (*value1Ptr > *value2Ptr)
    {
    int temp = *value1Ptr;
    *value1Ptr = *value2Ptr;
    *value2Ptr = temp;
    }

    if (*value1Ptr > *value3Ptr)
    {
    int temp = *value1Ptr;
    *value1Ptr = *value3Ptr;
    *value3Ptr = temp;
    }

    if (*value2Ptr > *value3Ptr)
    {
    int temp = *value2Ptr;
    *value2Ptr = *value3Ptr;
    *value3Ptr = temp;
    }

    return;

} // end sortByReference method
