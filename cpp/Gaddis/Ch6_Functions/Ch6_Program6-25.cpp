// This program demonstrates two uses of passing arguments by refrence

#include <iostream>
using namespace std;

// Function prototypes
void GetNums(int &, int &);    // Uses reference parameters to input
                               // values in the function, but to actually
                               // store them in variables defined in main

void OrderNums(int &, int &);  // Uses reference parameters to change the 
                               // values of existing values stored in main

int main()
{
    int small, big;

    // Call GetNums to input the 2 numbers
    GetNums(small, big);

    // Call OrderNums to sort the input
    OrderNums(small, big);
    
    // Display values
    cout << "The inputs sorted smallest to largest are: "
         << small << " " << big << endl;

    return 0;
}

void GetNums(int &input1, int &input2)
{
    cout << "Enter an integer: ";
    cin >> input1;
    cout << "Enter another integer: ";
    cin >> input2;
}

void OrderNums(int &num1, int &num2)
{
    int temp;
    
    if (num1 > num2)
    {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }
}
