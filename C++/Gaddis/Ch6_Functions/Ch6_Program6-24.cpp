// This program uses 2 function: a void function with a reference
// variable as a parameter, and a value-returning function.

#include <iostream>
using namespace std;

// Function prototypes
void GetNum(int &);
int DoubleNum(int);

int main()
{
    int value;
    
    // Call GetNum to get a number and store it in 'value'
    GetNum(value);
    
    // Call DoubleNum, passing it the number stored in 'value'
    // Assign 'value' the number returned by the Function
    value = DoubleNum(value);
    
    // Display the resulting number
    cout << "That value doubled is " << value << endl;
    
    return 0;
}

void GetNum(int &userNumber)
{
    cout << "Enter an integer: ";
    cin >> userNumber;
}

int DoubleNum(int number)
{
    return number * 2;
}
