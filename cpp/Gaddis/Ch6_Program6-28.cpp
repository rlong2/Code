// This program uses overloaded functions to square an int and double

#include <iostream>
using namespace std;

// Function prototypes
int Square(int);
double Square(double);

int main()
{
    int userInt;
    double userDouble;
    
    cout << "Enter an integer and a floating-point value: ";
    cin >> userInt >> userDouble;
    
    cout << "Here are their squares: "
         << Square(userInt)
         << " and "
         << Square(userDouble)
         << endl;

    return 0;
}

int Square(int number)
{
    return number * number;
}

double Square(double number)
{
    return number * number;
}
