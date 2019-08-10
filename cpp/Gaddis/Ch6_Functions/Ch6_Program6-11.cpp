// This program demonstrates a function that returns an int

#include <iostream>

using namespace std;

// Function Prototype
int Sum(int num1, int num2);

int main()
{
    int num1,
        num2,
        total;
        
    cout << "Enter two integers seperated by spaces: ";
    cin >> num1 >> num2;
    
    total = Sum(num1, num2);
    
    cout << "The sum is " << total;

    return 0;
}

int Sum(int num1, int num2)
{
    return num1 + num2;
}
