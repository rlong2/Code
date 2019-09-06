/* 
 *  Ryan Long: Extra Credit Request: Ex 2-14
 *
 *  Prompt the user to enter the size of the hard drive specified
 *  by the manufacturer, on the hard drive box.
 *  Output the actual storage capacity of the hard drive.
 *  Ex, 40 GB is really 37.25 GB
 *  
 * This version of the code rejects bad user input:
 *    -User cannot enter a negative hard drive size
 *    -User cannot enter a string for the hard drive size
 *    -User cannot enter multiple data at the size prompt, i.e., Enter GB: 40 333 -8 fourty, etc
 *    -User cannot enter multiple data at the continue (y/n) prompt, i.e., exit, continue, 83492, etc
 */

#include <iostream>
#include <iomanip>    
#include <cmath>
#include <limits.h>
using namespace std;

// Function Prototypes
int getDriveSize();
char getChoice();

// Main
int main() 
{
    long givenSize;           // How much space the box says you get
    long double actualSize;   // Holds how much space you really get
    char userChoice = 'y';    // Lets the user continue or exit program

    cout << "This program tells you how much space your hard drive really has!" << endl;
    
    // Get user input
    while (userChoice == 'y')
    {
        givenSize = getDriveSize();

        // If input is valid, calculate the actual hard drive size
        // Convert GB to kB, divide by 1024^3
        actualSize = (givenSize * 1000000000) / pow(1024, 3);

        // Output result
        cout << "The actual HD size is " << (double)actualSize << " GB." << endl;    

        userChoice = getChoice();
        
        while (userChoice != 'n' && userChoice != 'y')
        {
            cout << "Please enter y or n.";
            userChoice = getChoice();
        }
    }
    
    cout << "\nThank you for using the program!" << endl;
    
    return 0;
}

// Function Implementations
int getDriveSize()
{
    int givenSize = 0;
    
    cout << "\nEnter the size of HD specified by the manufacturer (in GB): ";
    cin  >> setw(1) >> givenSize;                                                 // Allows for only 1 input
    
    while (givenSize < 0)                                                         // Hard drive can't be less than 0 GB
    {
        cout << "A hard drive can't have a negative size!" << endl;
        cout << "\nEnter the size of HD specified by the manufacturer (in GB): ";
        cin  >> setw(1) >> givenSize;
    }
    // Error Checking
    while(cin.good() == false)                                                   // While input is not an integer...
    {
        cout << "Error. Please enter valid input." << endl;
        
        cin.clear();                                                             // clear input stream of all characters
        cin.ignore(INT_MAX, '\n');                                               // and ignore all possible newlines 
        
        // Get user input again
        cout << "\nEnter the size of HD specified by the manufacturer (in GB): ";
        cin  >> setw(1) >> givenSize;
    }
    
    // Clear stream again
    cin.clear();       
    cin.ignore(INT_MAX, '\n');
        
    return givenSize;
}

char getChoice()
{
    char choice;
    choice == 'y';
    cout << "\nDo you want to find the actual space of another hard drive? (y/n): ";
    cin  >> setw(1) >> choice;

    if (choice == 'y' || choice == 'n')
        return choice;
        
    // Error Checking
    while(cin.good() == false)                                                   
    {
        cout << "Error. Please enter valid input." << endl;
        
        cin.clear();                                                              
        cin.ignore(CHAR_MAX, '\n');                                                   
        
        // Get user input again
        cout << "\nDo you want to find the actual space of another hard drive? (y/n): ";
        cin  >> setw(1) >> choice;
    }
    
    // Clear stream again
    cin.clear();       
    cin.ignore(INT_MAX, '\n');
        
    return choice;
}
