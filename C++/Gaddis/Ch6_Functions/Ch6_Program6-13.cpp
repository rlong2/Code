// This program checks if an int is even or odd
// using a function that returns a bool

#include <iostream>

using namespace std;

// Function Prototype
bool CheckEven(int);

int main()
{
    int val;
    
    cout << "Enter an integer: ";
    cin >> val;
    
    if (CheckEven(val))
    {
        cout << val << " is even." << endl;
    } else
        cout << val << " is odd." << endl;
    
    return 0;
}

bool CheckEven(int number)
{
    if (number % 2 == 0)
    {
        return true;
    } else
        return false;
}
