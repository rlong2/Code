// Sending in multiple parameters to a void function

#include <iostream>

using namespace std;

// Function Prototype
void AddNums(int num1, int num2, int num3);

int main()
{

    int num1, num2, num3;

    cout << "Enter three integers seperated by spaces: ";
    cin >> num1 >> num2 >> num3;
    
    AddNums(num1, num2, num3);

    return 0;
}

void AddNums(int num1, int num2, int num3)
{
    cout << "The sum is " << num1 + num2 + num3 << endl;
}
