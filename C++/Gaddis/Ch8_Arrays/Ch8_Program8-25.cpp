// This program shows the use of a vector using range-based for loops

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    // Define a vector with a starting size of 5 elements
    vector<int> numbers(5);

    // Get values for the vector elements
    // A reference value is used to edit the elements
    for (int &val : numbers)
    {
        cout << "Enter an integer: ";
	cin  >> val;
    }

    // Display the elements
    cout << "\nHere are the elements entered: ";
    for (int val : numbers)
	    cout << val << " ";

    cout << endl;

    return 0;
}
