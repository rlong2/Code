// This program demonstrates that an array element
// can be passed to a function like any other variable

#include<iostream>
using namespace std;

void ShowValue(int);        // Function prototype
int main()
{
    const int SIZE = 8;
    int arrayNums[] = { 94, 84, 999, 26, -6 , -3278, 42, 11 };

    cout << "Displaying array contents: ";
    for (int i = 0; i < SIZE; i++)      // Send the array data to the function,
    {                                   // one element at a time.
        ShowValue(arrayNums[i]);
    }
    
    cout << endl;

    return 0;
}

// Function implementation
void ShowValue(int num)
{
    cout << num << " ";
}
