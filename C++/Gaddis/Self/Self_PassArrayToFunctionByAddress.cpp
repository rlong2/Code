// This porgam shows how to pass an entire array to a function
// by passing the array's memory address.

#include<iostream>
using namespace std;

// Function Prototype
void ShowValues(int myArray[], int size);


int main()
{
    const int SIZE = 6;
    int collection[SIZE] = { 4, 432, -32, 77, 1, -33 };

    cout << "The array contains the values: ";
    ShowValues(collection, SIZE);

    return 0;
}

// Function prototype
void ShowValues(int nums[], int size)
{
    for (int i = 0; i < size; i++)
	cout << nums[i] << " ";
   cout << endl; 
}
