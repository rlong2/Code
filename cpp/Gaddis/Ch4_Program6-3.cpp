// Demonstrates jumping from function to function (void return type, no paramters

#include <iostream>

using namespace std;

// Function Prototypes
void First();
void Second();

int main()
{
    cout << "In main." << endl;
    First();
    Second();
    cout << "Back in main." << endl;
    return 0;
}

void First()
{
    cout << "I'm in the First function." << endl;
}

void Second()
{
    cout << "I'm in the Second function." << endl;
}
