// This program demonstrates the vector size,
// push_back, and pop_back member functions

#include <iostream>
#include<vector>
using namespace std;

// Function prototype
void ShowValues(vector<int>);

int main()
{ 
    vector<int> nums;                    // Empty vector created

    // Store values in vector
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(4);
    nums.push_back(5);
    cout << "The size of the vector is " << nums.size() << endl;
    ShowValues(nums);                                   
    
    // Remove a value from vector
    cout << "\nPopping a value from vector..." << endl;
    nums.pop_back();
    cout << "The size of the vector is " << nums.size() << endl;
    ShowValues(nums);    
    
    return 0;
}

// Function implementation
void ShowValues(vector<int> myVec)
{
    cout << "Vector contains: ";
    for (int i = 0; i < myVec.size(); i++)
        cout << myVec[i] << " ";
    cout << endl;
}
