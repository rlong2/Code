// This program demonstrates the vector size member function
// Table 8-2 has vector examples (pg 565, Gaddis)
#include <iostream>
#include<vector>
using namespace std;

// Function prototype
void ShowValues(vector<int>);

int main()
{ 
    vector<int> nums;                    // Empty vector created
    vector<int>moreNums(4, 33);          // Puts int 33 into the vector four times
    vector<int>primes{2, 3, 5, 7, 11 };  // Puts 6 ints into the vector. Note the {} used
    
    for (int i = 0; i < 7; i++)          // Put data into the vector
        nums.push_back(i * 2);
    
    ShowValues(nums);                    // Call method to display data
    ShowValues(moreNums);
    ShowValues(primes);
    
    return 0;
}

// Function implementation
void ShowValues(vector<int> myNums)
{
    cout << "Vector contains: ";
    for (int i = 0; i < myNums.size(); i++)
        cout << myNums[i] << " ";
    cout << endl;
}
