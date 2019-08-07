// This program demonstrates the use of default function arguments

#include <iostream>
using namespace std;

// Function prototype with default arguments
void DisplayStars(int starsPerRow = 10, int numRows = 1);

int main()
{
    DisplayStars(); // Use default arguments
    
    DisplayStars(5); // 5 stars per row, default 1 row
  
    DisplayStars(20,7); // 20 stars per row, 7 numRows

    
    return 0;
}

void DisplayStars(int starsPerRow, int numRows)
{
    for (int row = 1; row <= numRows; row++)
    {
        for (int star = 1; star <= starsPerRow; star++)
        {
            cout << "*";
        }
        cout << endl;
    }
}
