// This program copies one array into another

#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 6;
    int arrayA[SIZE] = { 10, 20, 30, 40, 50, 60 };
    int arrayB[SIZE] = { 1, 2, 3, 4, 5, 6 };
    
    cout << "Contents of arrayA: ";
    for (int var : arrayA)
    {
        cout << var << " ";
    }
    
        cout << "\nContents of arrayB: ";
    for (int var : arrayB)
    {
        cout << var << " ";
    }
    
    cout << "\nCopying A to B..." << endl;
    for (int i = 0; i < SIZE; i++)
    {
        arrayB[i] = arrayA[i];
    }
    
        cout << "Contents of arrayA: ";
    for (int var : arrayA)
    {
        cout << var << " ";
    }
    
        cout << "\nContents of arrayB: ";
    for (int var : arrayB)
    {
        cout << var << " ";
    }
    
    return 0;
}
