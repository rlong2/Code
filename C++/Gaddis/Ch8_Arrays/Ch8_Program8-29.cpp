// This program demonstrates how to clear a vector array

#include <iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> myNums{ 3, 55, 30, 500, -44, 4893, 99 };
    
    cout << "Vector contains: ";
    for (int var : myNums)
        cout << var << " ";
        
    myNums.clear();
    cout << "\nVector cleared" << endl;
    
        cout << "Vector contains: ";
    for (int var : myNums)
        cout << var << " ";
        
    return 0;
}
