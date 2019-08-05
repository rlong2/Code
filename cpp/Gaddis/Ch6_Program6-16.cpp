// This program demonstrates how global variables work

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
    cout << "In AnotherFunction, num is " << num << endl;
    num = 2000;
    cout << "But now, num is " << num << endl;
}
