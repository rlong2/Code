/*  This program uses a reference variable as a function parameter.
* Reference variables are defined like regular variables,
* except there is an ampersand (&) between the data type and name.
* The & must appear in both the prototype and header.
* The & does not appear in a function call.
*/

#include <iostream>
using namespace std;

// Function prototype. The parameter is a reference variable
void DoubleNum(int &refVar);

int main()
{
    int num = 5;
    
    cout << "In main, num is " << num << endl;
    
    DoubleNum(num);
    
    cout << "Back in main, num is " << num << endl;
    
    return 0;
}

// Note that this function is void!
void DoubleNum(int &refVar)
{
    refVar = refVar * 2;  // doubles the value in main WITHOUT 'returning' a value
}
