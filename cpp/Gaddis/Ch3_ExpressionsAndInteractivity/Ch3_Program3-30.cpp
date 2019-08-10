// This program demonstrates how generating random numbers 
// WITHOUT a seed produces the same 'random' number forever.

#include <iostream>
#include <cstdlib> // needed to use 'rand'

using namespace std;

int main()
{
    cout << "Run this program repeatedly to see that the 'random' values do not change." << endl;

    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;

    cout << "\nNow a seed will be generated, making truly random values." << endl;

    unsigned seed;

    cout << "Enter a seed value: ";
    cin >> seed;

    // Set the random generator seed before calling rand()
    srand(seed);

    cout << rand() << endl;
    cout << rand() << endl;
    cout << rand() << endl;

    return 0;
}
