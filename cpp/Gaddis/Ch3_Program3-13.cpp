// This program uses setw to display three rows of numbers so they align.

#include <iostream>
#include <iomanip>   // needed for 'setw' 

using namespace std;

int main()
{
    // Initialize rows
    int num1 = 2423, num2 = 3,     num3 = 829,
	num4 = 69,   num5 = 999,   num6 = 12,
	num7 = 0,    num8 = 29222, num9 = 77;

    //Display rows
    cout << setw(6) << num1 << setw(6) << num2 << setw(6) << num3 << endl;
    cout << setw(6) << num4 << setw(6) << num5 << setw(6) << num6 << endl;
    cout << setw(6) << num7 << setw(6) << num8 << setw(6) << num9 << endl;

    return 0;
}
