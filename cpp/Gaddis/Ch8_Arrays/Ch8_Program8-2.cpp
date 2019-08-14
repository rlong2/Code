// This program stores employee work hours in an int array.
// One loop is used to input hours.
// Another loop is used to display them.

#include <iostream>
using namespace std;

int main()
{
    const int NUM_EMPLOYEES = 6;
    int hours[NUM_EMPLOYEES];

    cout << "Enter the hours worked by " << NUM_EMPLOYEES << " employees: ";
    for (int i = 0; i < NUM_EMPLOYEES; i++)
    {
        cin >> hours[i];
    }

    cout << "Here is the recorded data: ";
    for (int i = 0; i < NUM_EMPLOYEES; i++)
    {
         cout << hours[i] << " ";
    }

    cout << endl;

    return 0;
}

