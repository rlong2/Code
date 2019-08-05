// This program demonstrates how global variables work.
// MyFunction changes the value of num,
// and that change is carried through into main
// because the num variable is global.

#include <iostream>

using namespace std;

// Function Prototype
void MyFunction();

//Global variable
int num = 2;

int main()
{
    cout<<"In main, num is " << num << endl; 
    MyFunction();
    cout << "Back in main, num is " << num << endl; // num is now 2000
    return 0;
}

void MyFunction()
{
    cout << "In MyFunction, num is " << num << endl;
    num = 2000;
    cout << "MyFunction has changed num to " << num << endl;
}
