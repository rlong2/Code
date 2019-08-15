// This program sums the contents of an array

#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 6;
    int arrayNums[SIZE] = { 5, 23, 8, 57, 99, 123 };
    int total = 0;
    
    for (int i = 0; i < SIZE; i++)
    {
        total += arrayNums[i];
    }
    
    cout << "The array's total is: " << total;
    
    return 0;
}
