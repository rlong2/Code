// This program demonstrates how the 'setprecision' manipulator
// affects how a float is displayed.

#include <iostream>
#include <iomanip> // needed for 'setprecision'

using namespace std;

int main()
{
    double num1 = 132.8932,
	   num2 = 26.384;

    double quotient = num1 / num2;

    cout << quotient << endl;
    cout << setprecision(5) << quotient << endl;
    cout << setprecision(4) << quotient << endl;
    cout << setprecision(3) << quotient << endl;
    cout << setprecision(2) << quotient << endl;
    cout << setprecision(1) << quotient << endl;

    return 0;
}
