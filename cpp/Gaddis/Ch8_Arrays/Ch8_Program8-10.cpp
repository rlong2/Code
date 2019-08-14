// This program demonstrates the range-based for loop
// to modify the contents of an array.
// A reference variable is used to modify the contents of an intialized array.

#include<iostream>
#include<string>
using namespace std;

int main()
{
    const int SIZE = 5;
    string pokemon[SIZE] = { "Ditto1", "Ditto2", "Ditto3",
                             "Ditto4", "Ditto5" };
    
    // Get values for the array
    for (string &val : pokemon)
    {
        cout << "Enter a pokemon name: ";
        cin >> val;
    }
                         
    // Display the values in the array
    cout << "\nHere are the strings you entered:" << endl;
    
    for (string val : pokemon)
        cout << val << endl;
         
    return 0;
}
