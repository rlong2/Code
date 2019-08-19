// This program lets the user create an array

#include <iostream>
using namespace std;

// Function prototypes
void DisplayArray(int myArray[], int size);
void DisplayArray(string myArray[], int size);

int main()
{
    int choice;
    int size;

    cout << "This program lets you create an array.\n"
         << "1. Create an integer array.\n"
         << "2. Create a string array.\n\n"
         << "Your choice: ";
    cin  >> choice;

    if (choice == 1)
    {
        cout << "You have chosen to create an integer array.\n"
             << "How big do you want the array to be?\n"
             << "Array size: ";
         cin >> size;
         int intArray[size];

         cout << "Now input data into the array" << endl;
         for (int &val : intArray)
         {
             cin >> val;
         }
         cout << "array filled" << endl;

         DisplayArray(intArray, size);

    } else {
        cout << "You have chosen to create a string array.\n"
             << "How big do you want the array to be?\n"
             << "Array size: ";
         cin >> size;
         string stringArray[size];

         cout << "Now input data into the array" << endl;
         for (string &val : stringArray)
         {
             cin >> val;
         }
         cout << "array filled" << endl;

         DisplayArray(stringArray, size);
    }


    return 0;
}

// Function implementation
void DisplayArray(int myArray[], int size)
{
    cout << "Your array contains: ";
    for (int i = 0; i < size; i++)
    {
        cout << myArray[i] << " ";
    }

    cout << endl;
}

void DisplayArray(string myArray[], int size)
{
    cout << "Your array contains: ";
    for (int i = 0; i < size; i++)
    {
        cout << myArray[i] << " ";
    }

    cout << endl;
}
