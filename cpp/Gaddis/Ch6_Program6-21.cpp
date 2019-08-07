// This program shows that static local variables
// retain their values bewteen fucntion calls

#include <iostream>

using namespace std;

// Function prototype
void ShowStatic();

int main()
{
    for (int i = 0; i < 5; i++)
    {
        ShowStatic();
    }
    return 0;
}

void ShowStatic()
{
    static int numCalls = 0; // static local variable
    
    cout << "This function has been called " << ++numCalls << " times." << endl;
}
