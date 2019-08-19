// This program demonstrates the empty member function

#include <iostream>
#include<vector>
using namespace std;

// Function prototype
double avgVector(vector<int>);

int main()
{
    vector<int> values;          // Define a vector to hold int values 
    int numValues;               // Number of values to be stored
    double average;              // Average of the stored values
    
    // Get the number of values to average
    cout << "How many values do you wish to average? ";
    cin  >> numValues;
    
    // Get the values and store them in a vector
    for (int i = 0; i < numValues; i++)
    {
        int tempValue;
        
        cout << "Enter value: ";
        cin  >> tempValue;
        values.push_back(tempValue);
    }
    
    // Get the average of the values and display it
    average = avgVector(values);
    cout << "\nAverage: " << average << endl;
   
    return 0;
}

// Function Implementation
double avgVector(vector<int> myVec)
{
    int total = 0;            // Accumulator
    double avg = 0.0;
    
    if (myVec.empty())        // Determine if vector is empty
        cout << "No values to average" << endl;
    else
    {
        for (int i = 0; i < myVec.size(); i++)
            total += myVec[i];
        avg = static_cast<double>(total)/myVec.size();
    }
    
    return avg;
}
