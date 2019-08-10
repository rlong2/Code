// Have a function call another (void return type, no parameters

#include <iostream>

using namespace std;

// Function Prototypes
void Deep();
void Deeper();

int main()
{
    cout << "In main" << endl;
    Deep();
    cout << "Back in main" << endl;

    return 0;
}

void Deep()
{
    cout << "In Deep" << endl;
    Deeper();
    cout << "Back in Deep" << endl;
}

void Deeper()
{
    cout << "In Deeper" << endl;
}
