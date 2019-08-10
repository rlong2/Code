// This program demonstrates a function with a parameter

#include <iostream>

using namespace std;

// Function Prototype
void DisplayValue(int num);

int main()
{
    cout << "Passing some values to DisplayValue." << endl;
    DisplayValue(5);
    DisplayValue(42);
    DisplayValue(-4);
    DisplayValue(1000);
    DisplayValue(92);

    cout << "Back in main" << endl;
    return 0;
}

void DisplayValue(int num)
{
    cout << "The value is " << num << endl;
}
