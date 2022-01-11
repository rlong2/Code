// This program sums the contents of an array
// It also finds the average and highest value in the array

#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 6;
    int arrayNums[SIZE] = { 5, 23, 8, 57, 99, 123 };
    int total = 0;
    int average;
    int highest = arrayNums[0];
    
    for (int i = 0; i < SIZE; i++)
    {
        total += arrayNums[i];
        
        if (arrayNums[i] > highest)     // Find highest number
        {                               // by comparing 'highest' var
            highest = arrayNums[i];     // to the current val in arrayNums
        }
        

    }
    
    average = total / SIZE;
    
    cout << "The array's total is " << total << endl;
    cout << "The average value is " << average << endl;
    cout << "The highest number is " << highest << endl;
    return 0;
}
