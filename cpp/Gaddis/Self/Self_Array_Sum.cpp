// This program sums the contents of an array
// and finds the average value.

#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 6;
    int arrayNums[SIZE] = { 5, 23, 8, 57, 99, 123 };
    int total = 0;
    int average;
    
    for (int i = 0; i < SIZE; i++)
    {
        total += arrayNums[i];
    }
    
    average = total / SIZE;
    
    cout << "The array's total is " << total << endl;
    cout << "The average value is " << average << endl;
    
    return 0;
}
