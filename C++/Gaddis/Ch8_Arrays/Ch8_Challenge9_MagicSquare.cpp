/* A magic square is a 3x3 grid containing the numbers 1-9 where each row, column,
* and diagnol adds to 15.
*
* Write a program that simulates a magic square using a two-dimensional 3x3 array
* It should have a Boolean function isMagicSquare that accepts the array as argument,
* returning true if it is a magic square.
*
* Multidimensional arrays: https://www.learncpp.com/cpp-tutorial/65-multidimensional-arrays/
* On passing 2d arrays to a function: http://www.cplusplus.com/forum/beginner/73432/
* ^Example from Volatile Pulse
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Global constant variables
const int NUM_ROWS = 3;
const int NUM_COLS = 3;

// Function Prototypes
void displaySquare(int myArray[NUM_ROWS][NUM_COLS]);    // Display the 3x3 array
bool isMagicSquare(int myArray[NUM_ROWS][NUM_COLS]);    // Check if the 3x3 array is a magic square

int main()
{
    int square[NUM_ROWS][NUM_COLS];            // Declare a 3x3 array
    
    // Have user fill the array
    cout << "Enter 9 integers to create a square:\n";
    for (int row = 0; row < NUM_ROWS; row++)
    {
        for (int col = 0; col < NUM_COLS; col++)
        {
            cin >> square[row][col];
        }
    }
    
    displaySquare(square);
    
    if (isMagicSquare(square) == 1)
        cout << "\nIt is a Magic Square!" << endl;
    else
        cout << "\nNot a Magic Square!" << endl;
    

} // main
    

// Function Implementation
void displaySquare(int myArray[NUM_ROWS][NUM_COLS])
{
    cout << "\nHere is your square:\n";
    int formatting = 0;
    for (int row = 0; row < NUM_ROWS; row++)
    {
        for (int col = 0; col < NUM_COLS; col++)
        {
            cout << myArray[row][col] << " ";
            formatting++;
            if (formatting == 3 || formatting == 6 || formatting == 9)
                cout << endl;
        } 
    } 
}

bool isMagicSquare(int myArray[NUM_ROWS][NUM_COLS])
{
        for (int row = 0; row < NUM_ROWS; row++)
    {
        for (int col = 0; col < NUM_COLS; col++)
        {
            if (myArray[row][col] < 1 || myArray[row][col] > 9)      // If any number is less than 1 or greater than 9
                return false;                                        // It is not a magic square
        }
    }
    
    // Get data for three rows
    int row1 = myArray[0][0] + myArray[0][1] + myArray[0][2];
    int row2 = myArray[1][0] + myArray[1][1] + myArray[1][2];
    int row3 = myArray[2][0] + myArray[2][1] + myArray[2][2];
    
    // Get data for three columns
    int col1 = myArray[0][0] + myArray[1][0] + myArray[2][0];
    int col2 = myArray[0][1] + myArray[1][1] + myArray[2][1];
    int col3 = myArray[0][2] + myArray[1][2] + myArray[2][2];
    
    // Get data for diagnols
    int diag1 = myArray[0][0] + myArray[1][1] + myArray[2][2];
    int diag2 = myArray[2][0] + myArray[2][1] + myArray[2][2];
    
    if (row1 != 15 || row2 != 15 || row3 != 15 ||
        col1 != 15 || col2 != 15 || col3 != 15 ||
        diag1 != 15|| diag2!= 15)
            return false;
            
    return true;    
}
