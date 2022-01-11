// This program passes an entire array to a function

#include<iostream>
using namespace std;

// Function Prototype
void ShowValues(int myArray[], int size);

int main()
{
    const int SIZE = 8;
    int collection[SIZE] = { 5, -42, 8, 822, 68, 11, 66, 100 };
    
    cout << "The array contains: ";
    ShowValues(collection, SIZE);

    return 0;
}

// Function Implementation
void ShowValues(int nums[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << nums[i] << " ";
    }

    cout << endl;
}
