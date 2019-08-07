// This program shows that local variables do not
// retain their values bewteen fucntion calls

#include <iostream>

using namespace std;

// Function prototype
void MyFunk();

int main()
{
    MyFunk();
    MyFunk();

    return 0;
}

void MyFunk()
{
    int val = 5;
    
    cout << "val is " << val << endl;
    val = 1000;                       // destroyed when function terminates
}
