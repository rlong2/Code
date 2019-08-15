// This program checks if two arrays are equal

#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 6;
    int arrayA[SIZE] = { 10, 20, 30, 40, 50, 60 };
    int arrayB[SIZE] = { 1, 2, 3, 4, 5, 6 };
    int arrayC[SIZE] = { 10, 20, 30, 40, 50, 60 };
    bool arraysEqual = true;
    int i = 0;                 // counter
    
    while (arraysEqual && i < SIZE)
    {
        if(arrayA[i] != arrayC[i])
        {
            arraysEqual = false;
        }
        
        i++;
    }
    
    if (arraysEqual)
        cout << "The arrays are equal." << endl;
    else
        cout << "The arrays are not equal." << endl;
    
    return 0;
}
