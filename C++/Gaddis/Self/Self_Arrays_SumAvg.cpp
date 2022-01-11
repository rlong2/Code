// This program gets the sum, average, highest, and lowest numbers in an array.

#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 6;
    int arrayNums[SIZE] = { 20, 43, 99, 832, -4, 69 };

    int highest = arrayNums[0],
	lowest =  arrayNums[0],
	total,
	average;

    for (int i = 0; i < SIZE; i++)
    {
        total += arrayNums[i];        // Incrementally sum values to get to get total sum
        
        if (arrayNums[i] > highest)
	    highest = arrayNums[i];

        if (arrayNums[i] < lowest)
	    lowest = arrayNums[i];	
    }

    average = total / SIZE;

    // Display results
    cout << "The sum of values in the array: " << total << endl;
    cout << "The average of values in the array: " << average << endl;
    cout << "The highest value in the array: " << highest << endl;
    cout << "The lowest value in the array: " << lowest << endl;

    return 0;
}
