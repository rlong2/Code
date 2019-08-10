// This program shows the size of various data types

#include <iostream>

using namespace std;

int main()
{
    double apple;

    cout << "The size of a short integer is " << sizeof(short) << " bytes." << endl;
    cout << "The size of a long integer is " << sizeof(long) << " bytes." << endl;
    cout << "An apple can be eaten in " << sizeof(apple) << " bytes." << endl;
    return 0;
}
