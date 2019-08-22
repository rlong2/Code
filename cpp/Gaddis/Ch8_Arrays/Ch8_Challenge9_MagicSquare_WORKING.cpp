/* A magic square is a 3x3 grid containing the numbers 1-9 where each row, column,
* and diagnol adds to 15.
*
* Write a program that simulates a magic square using a two-dimensional 3x3 array
* It should have a Boolean function isMagicSquare that accepts the array as argument,
* returning true if it is a magic square.
*
* Multidimensional arrays: https://www.learncpp.com/cpp-tutorial/65-multidimensional-arrays/
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototypes
bool isMagicSquare(int *myArray[row][col]);

int main()
{
    // Constant variables
    const int NUM_ROWS = 3;
    const int NUM_COLS = 3;

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
    
    // Display the square
    cout << "\nHere is your square:\n";
    int formatting = 0;
    for (int row = 0; row < NUM_ROWS; row++)
    {
        for (int col = 0; col < NUM_COLS; col++)
        {
            cout << square[row][col] << " ";
            formatting++;
            if (formatting == 3 || formatting == 6)
                cout << endl;
        } 
    } 
    
} // main
    

// Function Implementation
bool isMagicSquare(int *myArray[row][col])
{
    for (int row = 0; row < NUM_ROWS; row++)
    {
        for (int col = 0; col < NUM_COLS; col++)
        {
            cout << square[row][col] << " ";
            formatting++;
            if (formatting == 3 || formatting == 6)
                cout << endl;
        } 
    } 
}
