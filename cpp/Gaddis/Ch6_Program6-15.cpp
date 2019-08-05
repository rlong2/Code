// This program shows how local variables work

#include <iostream>

using namespace std;

void MyFunction();

int main()
{
    int num = 1; // local variable in main
    
    cout << "In main, number is " << num << endl;
    
    MyFunction();
    
    cout << "Back in main, number is " << num << endl;
    return 0;
}

void MyFunction()
{
    int num = 20;
    cout << "In MyFunction, number is " << num << endl;
}
